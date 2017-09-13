#ifndef IBUFFER_H_
#define IBUFFER_H_

//#include "IRenderer.h"
class IRenderer;

class IBuffer {
public:
	virtual void createBuffer(IRenderer& _renderer) = 0;
	virtual void setBuffer(IRenderer& _renderer, void *_value) = 0;
};

#endif // !IBUFFER_H_
