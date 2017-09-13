#ifndef D3DVERTEXBUFFER_H_
#define D3DVERTEXBUFFER_H_

#include "IVertexBuffer.h"
#include "IRenderer.h"
#include <D3D11.h>

class D3DVertexBuffer : public IVertexBuffer
{
public:
	D3DVertexBuffer();
	~D3DVertexBuffer();
	virtual void createBuffer(IRenderer & renderer, const Vertex vertices[], int size);
	virtual void setBuffer(IRenderer& renderer);
	virtual void update(IRenderer & renderer, const Vertex vertices[], int size);
private:
	ID3D11Buffer *m_vertexBuffer;
};

#endif // !D3DVERTEXBUFFER_H_