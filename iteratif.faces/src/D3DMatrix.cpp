#include "D3DMatrix.h"

using namespace DirectX;

D3DMatrix::D3DMatrix()
{
}

D3DMatrix::D3DMatrix(XMMATRIX _matrix)
{
	m_matrix = _matrix;
}

D3DMatrix::~D3DMatrix()
{
}

void D3DMatrix::Identity()
{
	m_matrix = XMMatrixIdentity();
}

void D3DMatrix::Multiply(IMatrix *_m)
{
	XMMATRIX m = *((XMMATRIX*)_m->Raw());
	m_matrix = XMMatrixMultiply(m_matrix, m);
}

void D3DMatrix::Inverse(IMatrix **_invMatrix)
{
	XMVECTOR determinant = XMMatrixDeterminant(m_matrix);
	XMMATRIX m = XMMatrixInverse(&determinant, m_matrix);
	D3DMatrix *inv = new D3DMatrix(m);
	*_invMatrix = inv;
}

void D3DMatrix::Scale(float _x, float _y, float _z)
{
	m_matrix = XMMatrixScaling(_x, _y, _z);
}

void D3DMatrix::RotationZ(float _angle)
{
	m_matrix = XMMatrixRotationZ(XMConvertToRadians(_angle));
}

void D3DMatrix::Translate(float _x, float _y, float _z)
{
	m_matrix = XMMatrixTranslation(_x, _y, _z);
}

void* D3DMatrix::Raw()
{
	return &m_matrix;
}
