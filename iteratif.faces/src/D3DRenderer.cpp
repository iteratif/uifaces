#include "D3DRenderer.h"
#include "FacesEngine.h"
#include "itString.h"
#include "D3DMatrix.h"
#include "AlphaBuffer.h"
#include "D3DIndexBuffer.h"
#include "D3DVertexBuffer.h"
#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <DDSTextureLoader.h>

using namespace DirectX;

D3DRenderer::D3DRenderer(ID3D11Device *_device)
	: m_enabled3D( false )
	, m_screenBuffer(nullptr)
	, m_firstDraw(true)
	, m_size(0)
	, m_renderTargetView(nullptr)
	, m_worldBuffer(nullptr)
	, m_matrixBuffer(nullptr)
	, m_pBlendStateNoBlend(nullptr)
	, m_worldMatrix(nullptr) {
	m_device = _device;
	if (m_device != nullptr) {
		m_device->GetImmediateContext(&m_deviceContext);
	}
	CreateMatrix(&m_worldMatrix);
	m_worldMatrix->Identity();
}

D3DRenderer::~D3DRenderer(void) {
	Release(m_worldBuffer);
	Release(m_screenBuffer);
	Release(m_matrixBuffer);
	Release(m_pBlendStateNoBlend);
	Release(m_renderTargetView);
	Release(m_deviceContext);
	if (m_worldMatrix != nullptr)
	{
		delete m_worldMatrix;
	}
}

void D3DRenderer::BeginFrame() {
	
}

bool D3DRenderer::Init(/*HWND hwnd, itString _shadersPath*/ ) {
	HRESULT hr;

	// Compile the pixel shader
	ID3DBlob* pVSBlob = nullptr;
	loadShader("shaders/vertexShader.cso", &pVSBlob);

	// Compile the pixel shader
	ID3DBlob* pPSBlob = nullptr;
	loadShader("shaders/pixelShader.cso", &pPSBlob);

	D3D11_BUFFER_DESC matrixBufferDesc;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBufferType);
	matrixBufferDesc.Usage = D3D11_USAGE_DEFAULT;//D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = 0;// D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	XMMATRIX world = XMMatrixIdentity();
	world._22 *= -1;
	XMMATRIX trans = XMMatrixTranslation( -/*viewport.Width*/800 * 0.5,/*viewport.Height*/600 * 0.5, 0.0f );
	trans = XMMatrixMultiply( world,trans  );
	
	XMFLOAT4X4 t;
	XMStoreFloat4x4(&t, XMMatrixTranspose(trans));

	MatrixBufferType cb;
	cb.trans = t;

	D3D11_SUBRESOURCE_DATA matrixSubData;
	matrixSubData.pSysMem = &cb;
	matrixSubData.SysMemPitch = 0;
	matrixSubData.SysMemSlicePitch = 0;

	hr = m_device->CreateBuffer(&matrixBufferDesc, &matrixSubData, &m_matrixBuffer);

	D3D11_BUFFER_DESC screenBufferDesc;
	screenBufferDesc.ByteWidth = sizeof(ScreenBufferType);
	screenBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	screenBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	screenBufferDesc.CPUAccessFlags = 0;
	screenBufferDesc.MiscFlags = 0;
	screenBufferDesc.StructureByteStride = 0;

	ScreenBufferType sb;
	sb.screen.x = 800/*viewport.Width*/;
	sb.screen.y = 600/*viewport.Height*/;

	D3D11_SUBRESOURCE_DATA screenSubData;
	screenSubData.pSysMem = &sb;
	screenSubData.SysMemPitch = 0;
	screenSubData.SysMemSlicePitch = 0;

	hr = m_device->CreateBuffer(&screenBufferDesc, &screenSubData, &m_screenBuffer);

	D3D11_BUFFER_DESC desc;
	desc.ByteWidth = sizeof(TranfBufferType);
	desc.Usage = D3D11_USAGE_DYNAMIC;
	desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	desc.MiscFlags = 0;
	desc.StructureByteStride = 0;

	XMFLOAT4X4 tran;
	XMStoreFloat4x4(&tran, XMMatrixTranspose(XMMatrixIdentity()));

	TranfBufferType tbt;
	tbt.world = tran;

	D3D11_SUBRESOURCE_DATA subData;
	subData.pSysMem = &tbt;
	subData.SysMemPitch = 0;
	subData.SysMemSlicePitch = 0;

	m_device->CreateBuffer(&desc, &subData, &m_worldBuffer);

	ID3D11VertexShader*	vertexShader;
	ID3D11PixelShader*	pixelShader;
	ID3D11InputLayout*	inputLayout;

	m_device->CreateVertexShader(pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), nullptr, &vertexShader);
	m_device->CreatePixelShader(pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), nullptr, &pixelShader);

	D3D11_INPUT_ELEMENT_DESC layout[] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	m_device->CreateInputLayout(layout, 2, pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), &inputLayout);

	m_deviceContext->IASetInputLayout(inputLayout);

	m_deviceContext->VSSetShader(vertexShader, nullptr, 0);
	ID3D11Buffer* matrixBuffer = getConstantMatrix();
	m_deviceContext->VSSetConstantBuffers(0, 1, &matrixBuffer);
	m_deviceContext->VSSetConstantBuffers(1, 1, &m_screenBuffer);

	m_deviceContext->PSSetShader(pixelShader, nullptr, 0);

	D3D11_BLEND_DESC blendDesc;
	ZeroMemory(&blendDesc, sizeof(D3D11_BLEND_DESC));
	blendDesc.AlphaToCoverageEnable = false;
	blendDesc.IndependentBlendEnable = false;

	blendDesc.RenderTarget[0].BlendEnable = true;
	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	m_device->CreateBlendState(&blendDesc, &m_pBlendStateNoBlend);
	m_deviceContext->OMSetBlendState(m_pBlendStateNoBlend, 0, 0xffffffff);

	pVSBlob->Release();
	pPSBlob->Release();

	inputLayout->Release();
	pixelShader->Release();
	vertexShader->Release();

	return true;
}

void* D3DRenderer::GetDevice() const {
	return m_device;
}

void* D3DRenderer::GetContextDevice() const {
	return m_deviceContext;
}

ID3D11Buffer* D3DRenderer::getConstantMatrix() const {
	return m_matrixBuffer;
}

int D3DRenderer::loadShader(const char *_filename, ID3DBlob **_blob) {
	HRESULT hr;
	ID3DBlob* pBlob = nullptr;
	itString path = m_engine->getRootPath();
	path.append(_filename);
	size_t newSize = path.size() + 1;
	wchar_t *wPath = new wchar_t[newSize];
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wPath, newSize, path, _TRUNCATE);
	hr = D3DReadFileToBlob(wPath, &pBlob);
	if (FAILED(hr)) {
		return 1;
	}
	*_blob = pBlob;
	return 0;
}

IVertexBuffer* D3DRenderer::CreateVertexBuffer(Vertex _vertices[], int _size) {
	D3DVertexBuffer *vertexBuffer = new D3DVertexBuffer();
	vertexBuffer->createBuffer(*this, _vertices, _size);
	return vertexBuffer;
}

IIndexBuffer* D3DRenderer::CreateIndexBuffer(unsigned short _indices[], int _size) {
	D3DIndexBuffer *indexBuffer = new D3DIndexBuffer();
	indexBuffer->createBuffer(*this,_indices, _size);
	return indexBuffer;
}

IBuffer* D3DRenderer::CreateBuffer() {
	AlphaBuffer *buffer = new AlphaBuffer();
	buffer->createBuffer(*this);
	return buffer;
}

void D3DRenderer::CreateTexture(const char *_filename, Texture **_texture) {
	ID3D11ShaderResourceView *resourceView = nullptr;
	ID3D11Resource *resource = nullptr;
	ID3D11SamplerState *samplerState = nullptr;
	
	D3DTexture *texture = new D3DTexture();

	const int len = strlen(_filename);
	wchar_t *wfilename = new wchar_t[len + 1];
	mbstowcs(wfilename, _filename, len);
	wfilename[len] = '\0';

	CreateDDSTextureFromFile(m_device, wfilename, &resource,&texture->ResourceView);
	ID3D11Texture2D *pTextureInterface = nullptr;
	resource->QueryInterface<ID3D11Texture2D>(&pTextureInterface);
	D3D11_TEXTURE2D_DESC desc;
	pTextureInterface->GetDesc(&desc);

	D3D11_SAMPLER_DESC samplerDesc;
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	// Create the texture sampler state.
	m_device->CreateSamplerState(&samplerDesc, &texture->SamplerState);

	texture->Width = desc.Width;
	texture->Height = desc.Height;

	pTextureInterface->Release();
	resource->Release();
	*_texture = texture;
}

void D3DRenderer::SetTexture(/*Texture *_texture*/int _id)
{
	FacesEngine& engine = GetEngine();
	ResourceManager& resourceManager = engine.GetResourceManager();

	D3DTexture *texture = static_cast<D3DTexture*>(resourceManager.GetTextureById(_id));
	m_deviceContext->PSSetShaderResources(0, 1, &texture->ResourceView);
	m_deviceContext->PSSetSamplers(0, 1, &texture->SamplerState);
}

//*********************************************************************
//	TRANSFORMATION
//*********************************************************************

void D3DRenderer::PushTransform(IMatrix *_world ) {
	m_worldMatrix->Multiply(_world);
}

void D3DRenderer::PopTransform(IMatrix *_world) {
	IMatrix *invWorld = nullptr;
	_world->Inverse(&invWorld);
	m_worldMatrix->Multiply(invWorld);
	delete invWorld;
}


//*********************************************************************
//	UPDATE & DRAW
//*********************************************************************

void D3DRenderer::Update(VisualElement& _container) {
	if (m_firstDraw) {
		m_firstDraw = false;
		_container.init(*this);
	} else {
		_container.update(*this);
	}
}

void D3DRenderer::Draw(VisualElement& _element) {
	m_deviceContext->VSSetConstantBuffers(2, 1, &m_worldBuffer);
	_element.draw(*this);
}

void D3DRenderer::DrawIndexed( unsigned int indexCount, unsigned int startIndexLocation, unsigned int baseVertexLocation ) {
	XMFLOAT4X4 t;
	XMStoreFloat4x4(&t, XMMatrixTranspose(*((XMMATRIX*)m_worldMatrix->Raw())));
	
	D3D11_MAPPED_SUBRESOURCE resource;
	m_deviceContext->Map(m_worldBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);
	memcpy(resource.pData, &t, sizeof(t));
	m_deviceContext->Unmap(m_worldBuffer, 0);
	m_deviceContext->DrawIndexed( indexCount, startIndexLocation, baseVertexLocation );
}

//*********************************************************************
//	
//*********************************************************************

void D3DRenderer::setEnable3D( bool value ) {
	m_enabled3D = value;
}

void D3DRenderer::CreateMatrix(IMatrix **_matrix)
{
	D3DMatrix *m = new D3DMatrix();
	*_matrix = m;
}
