#ifndef SQUARE_H_
#define SQUARE_H_

//SS#include "faces.h"

#include "D3DRenderer.h"
#include "VisualElement.h"
#include <D3D11.h>

class Square : public VisualElement
{
public:
	Square(float _x, float _y, float _w, float _h );
	~Square();

	virtual void draw(D3DRenderer& renderer);

private:
	ID3D11ShaderResourceView *m_d3dSquareSRV;
};

#endif; // SQUARE_H_
