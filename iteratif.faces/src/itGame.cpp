#include "itGame.h"

itGame::itGame()
	: m_engine(nullptr)
	, m_renderer(nullptr)
	, m_device(nullptr)
	, m_deviceContext(nullptr)
	, m_swapChain(nullptr)
	, m_renderTargetView(nullptr)
	, m_depthStencilView(nullptr)
	, m_depthStencilState(nullptr)
	, m_rasterizerState(nullptr)
	, m_depthStencilBuffer(nullptr)
{
	
}

itGame::~itGame()
{
	delete m_engine;
	Release(m_rasterizerState);
	Release(m_depthStencilState);
	Release(m_depthStencilView);
	Release(m_renderTargetView);
	Release(m_swapChain);
	Release(m_deviceContext);
	Release(m_device);
}

bool itGame::init(HWND _hwnd, itString *_rootPath, UINT _width, UINT _height)
{
	UINT createDeviceFlags = 0;
	D3D_DRIVER_TYPE	driverType;
	D3D_FEATURE_LEVEL featureLevel;

#ifndef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};

	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3
	};

	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = _hwnd;
	swapChainDesc.SampleDesc.Count = 4;
	swapChainDesc.Windowed = true;

	HRESULT result;
	for (UINT i = 0; i < numDriverTypes; i++) {
		result = D3D11CreateDeviceAndSwapChain(NULL, driverTypes[i], NULL, createDeviceFlags,
			featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &swapChainDesc, &m_swapChain, &m_device,
			&featureLevel, &m_deviceContext);
		if (SUCCEEDED(result)) {
			driverType = driverTypes[i];
			break;
		}
	}

	ID3D11Texture2D*	backBuffer;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
	result = m_device->CreateRenderTargetView(backBuffer, NULL, &m_renderTargetView);
	if (FAILED(result)) {
		return false;
	}
	Release(backBuffer);

	// Create the depth buffer for use with the depth/stencil view.
	D3D11_TEXTURE2D_DESC depthStencilBufferDesc;
	ZeroMemory(&depthStencilBufferDesc, sizeof(D3D11_TEXTURE2D_DESC));

	depthStencilBufferDesc.ArraySize = 1;
	depthStencilBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencilBufferDesc.CPUAccessFlags = 0; // No CPU access required.
	depthStencilBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilBufferDesc.Width = _width;
	depthStencilBufferDesc.Height = _height;
	depthStencilBufferDesc.MipLevels = 1;
	depthStencilBufferDesc.SampleDesc.Count = 1;
	depthStencilBufferDesc.SampleDesc.Quality = 0;
	depthStencilBufferDesc.Usage = D3D11_USAGE_DEFAULT;

	result = m_device->CreateTexture2D(&depthStencilBufferDesc, nullptr, &m_depthStencilBuffer);
	if (FAILED(result))
	{
		MessageBoxA(_hwnd, "Failed to create the Depth/Stencil texture.", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	result = m_device->CreateDepthStencilView(m_depthStencilBuffer, nullptr, &m_depthStencilView);
	if (FAILED(result))
	{
		MessageBoxA(_hwnd, "Failed to create DepthStencilView.", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	// Setup depth/stencil state.
	D3D11_DEPTH_STENCIL_DESC depthStencilStateDesc;
	ZeroMemory(&depthStencilStateDesc, sizeof(D3D11_DEPTH_STENCIL_DESC));

	depthStencilStateDesc.DepthEnable = TRUE;
	depthStencilStateDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilStateDesc.DepthFunc = D3D11_COMPARISON_LESS;
	depthStencilStateDesc.StencilEnable = FALSE;

	result = m_device->CreateDepthStencilState(&depthStencilStateDesc, &m_depthStencilState);
	if (FAILED(result)) {
		MessageBoxA(_hwnd, "Failed to create a DepthStencilState object.", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	m_deviceContext->OMSetDepthStencilState(m_depthStencilState, 1);

	// Setup rasterizer state.
	D3D11_RASTERIZER_DESC rasterizerDesc;
	ZeroMemory(&rasterizerDesc, sizeof(D3D11_RASTERIZER_DESC));

	rasterizerDesc.AntialiasedLineEnable = FALSE;
	rasterizerDesc.CullMode = D3D11_CULL_BACK;
	rasterizerDesc.DepthBias = 0;
	rasterizerDesc.DepthBiasClamp = 0.0f;
	rasterizerDesc.DepthClipEnable = TRUE;
	rasterizerDesc.FillMode = D3D11_FILL_SOLID;
	rasterizerDesc.FrontCounterClockwise = FALSE;
	rasterizerDesc.MultisampleEnable = FALSE;
	rasterizerDesc.ScissorEnable = FALSE;
	rasterizerDesc.SlopeScaledDepthBias = 0.0f;

	// Create the rasterizer state object.
	result = m_device->CreateRasterizerState(&rasterizerDesc, &m_rasterizerState);
	if (FAILED(result)) {
		MessageBoxA(_hwnd, "Failed to create a RasterizerState object.", "Error", MB_OK | MB_ICONERROR);
		return false;
	}
	m_deviceContext->RSSetState(m_rasterizerState);

	CD3D11_VIEWPORT viewport;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = (FLOAT)_width;
	viewport.Height = (FLOAT)_height;
	viewport.MinDepth = 0.1f;
	viewport.MaxDepth = 1.0f;
	m_deviceContext->RSSetViewports(1, &viewport);

	m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, NULL);

	m_renderer = new D3DRenderer(m_device/*,m_deviceContext*/);
	m_engine = new FacesEngine(_rootPath);
	m_engine->init(m_renderer);

	return true;
}

bool itGame::loadContent(itString *_view)
{
	m_engine->load(_view);
	Initialized();
	return false;
}

void itGame::endFrame() {
	// Switch back buffer to front buffer
	m_swapChain->Present(0, 0);
}

int itGame::run() {
	MSG msg = { 0 };

	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT || msg.message == WM_DESTROY)
			{
				break;
			}
		}

		float clearColor[] = { 0, 0, 0, 1 };
		m_deviceContext->ClearRenderTargetView(m_renderTargetView, clearColor);

		Render();
		m_engine->render();

		endFrame();
	}

	return 0;
}
