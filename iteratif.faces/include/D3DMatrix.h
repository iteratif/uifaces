#ifndef D3DMATRIX_H_
#define D3DMATRIX_H_

#include "itMatrix.h"
#include <DirectXMath.h>

class D3DMatrix : public IMatrix
{
public:
	D3DMatrix();
	D3DMatrix(DirectX::XMMATRIX _matrix);
	~D3DMatrix();

	virtual void Identity();
	virtual void Multiply(IMatrix *_m);
	virtual void Inverse(IMatrix **_invMatrix);
	virtual void* Raw();

	virtual void Scale(float _x, float _y, float _z) ;
	virtual void RotationZ(float _angle) ;
	virtual void Translate(float _x, float _y, float _z);
private:
	DirectX::XMMATRIX m_matrix;
};

#endif // !D3DMATRIX_H_


