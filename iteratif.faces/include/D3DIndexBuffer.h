#ifndef D3DINDEXBUFFER_H_
#define D3DINDEXBUFFER_H_

#include "IIndexBuffer.h"
#include "IRenderer.h"
#include <D3D11.h>

class D3DIndexBuffer : public IIndexBuffer
{
public:
	D3DIndexBuffer();
	~D3DIndexBuffer();
	virtual void createBuffer(IRenderer & renderer, unsigned short indices[], int size);
	virtual void setBuffer(IRenderer& renderer);
private:
	ID3D11Buffer *m_indexesBuffer;
};

#endif // D3DINDEXBUFFER_H_

