#ifndef GRAPHICRENDERER_H_
#define GRAPHICRENDERER_H_

#include "VisualElement.h"
#include "IRenderer.h"
#include "ResourceManager.h"
#include "faces.h"
#include "faces_types.h"
#include "itMatrix.h"
#include <D3D11.h>

class Texture;

class D3DTexture : public Texture
{
public:
	ID3D11ShaderResourceView	*ResourceView;
	ID3D11SamplerState			*SamplerState;

	D3DTexture()
		: ResourceView(nullptr)
		, SamplerState(nullptr)
	{

	}

	D3DTexture(ID3D11ShaderResourceView *_resourceView, ID3D11SamplerState *_samplerState)
	: ResourceView(_resourceView)
	, SamplerState(_samplerState) {

	}

	~D3DTexture() {
		Release(ResourceView);
		Release(SamplerState);
	}
};

class D3DRenderer : public IRenderer
{
public:
	D3DRenderer(ID3D11Device *_device);
	~D3DRenderer(void);

	virtual void			BeginFrame();
	virtual bool			Init();
	virtual void			Update(VisualElement& _element);
	virtual void			Draw(VisualElement& _element);
	virtual void			CreateMatrix(IMatrix **_matrix);
	virtual void			CreateTexture(const char *_filename, Texture **_texture);
	virtual void			SetTexture(int _id);


	void*					GetDevice() const;
	void*					GetContextDevice() const;
	ID3D11Buffer*			getConstantMatrix() const;

	int						loadShader(const char *_filename, ID3DBlob **_blob);
	
	IVertexBuffer*			CreateVertexBuffer( Vertex vertices[], int size );
	IIndexBuffer*			CreateIndexBuffer(unsigned short indices[], int size);
	IBuffer*				CreateBuffer();
	
	void					DrawIndexed( unsigned int indexCount, unsigned int startIndexLocation, unsigned int baseVertexLocation );
	
	void					setEnable3D( bool value );

	void					PushTransform(IMatrix *_world);
	void					PopTransform(IMatrix *_world);

protected:
	int						m_size;

	ID3D11Device*			m_device;
	ID3D11DeviceContext*	m_deviceContext;
	ID3D11RenderTargetView*	m_renderTargetView;
	ID3D11DepthStencilState* m_depthDisabledStencilState;
	ID3D11BlendState*		m_pBlendStateNoBlend;

	/*XMMATRIX*/IMatrix		*m_worldMatrix;

	ID3D11Buffer			*m_worldBuffer;
	ID3D11Buffer*			m_matrixBuffer;
	ID3D11Buffer*			m_screenBuffer;

	D3D_DRIVER_TYPE			m_DriverType;
	D3D_FEATURE_LEVEL		m_FeatureLevel;

	bool					m_enabled3D;
	bool					m_firstDraw;
};

#endif // GRAPHICRENDERER_H_
