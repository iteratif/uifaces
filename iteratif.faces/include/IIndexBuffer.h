#ifndef IINDEXBUFFER_H_
#define IINDEXBUFFER_H_

//#include "IRenderer.h"

class IRenderer;

class IIndexBuffer {
public:
	virtual void createBuffer(IRenderer& _renderer, unsigned short _indices[], int _size) = 0;
	virtual void setBuffer(IRenderer& _renderer) = 0;
};

#endif // IINDEXBUFFER_H_

