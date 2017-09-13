#ifndef IVERTEXBUFFER_H_
#define IVERTEXBUFFER_H_

//#include "faces.h"
#include "faces_types.h"

class IRenderer;

class IVertexBuffer
{
public:
	virtual void createBuffer(IRenderer& renderer, const Vertex vertices[], int size ) = 0;
	virtual void setBuffer(IRenderer& renderer) = 0;
	virtual void update(IRenderer& renderer, const Vertex vertices[], int size) = 0;
};

#endif; // IVERTEXBUFFER_H_
