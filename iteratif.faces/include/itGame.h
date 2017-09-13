#ifndef ITGAME_H_
#define ITGAME_H_

#include "itString.h"
#include "D3DRenderer.h"
#include "FacesEngine.h"

#include <D3D11.h>
#include <DDSTextureLoader.h>
#include <DirectXMath.h>
#include <D3Dcompiler.h>


class itGame {
public:
	itGame();
	~itGame();

	bool init(HWND _hwnd, itString *_rootPath, UINT _width, UINT _height);
	bool loadContent(itString *_view);
	virtual void Initialized() {}
	virtual void Render() {}
	int run();
	void endFrame();

	FacesEngine* GetEngine() const { return m_engine; }

protected:
	ID3D11Device				*m_device;
	ID3D11DeviceContext			*m_deviceContext;
	IDXGISwapChain				*m_swapChain;
	ID3D11RenderTargetView		*m_renderTargetView;
	ID3D11DepthStencilView		*m_depthStencilView;
	ID3D11Texture2D				*m_depthStencilBuffer;

	ID3D11RasterizerState		*m_rasterizerState;
	ID3D11DepthStencilState		*m_depthStencilState;

	FacesEngine					*m_engine;
	D3DRenderer					*m_renderer;
};

#endif // !ITGAME_H_

