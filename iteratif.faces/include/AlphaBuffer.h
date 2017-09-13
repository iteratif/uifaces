#ifndef BUFFER_H_
#define BUFFER_H_

#include "IBuffer.h"
#include "IRenderer.h"
#include <D3D11.h>

class AlphaBuffer : public IBuffer {
public:
	AlphaBuffer();
	~AlphaBuffer();

	virtual void createBuffer(IRenderer& _renderer);
	virtual void setBuffer(IRenderer& _renderer, void *_value);
protected:
	ID3D11Buffer	*m_buffer;
};

#endif // !BUFFER_H_
