#include "D3DIndexBuffer.h"
#include "faces.h"

D3DIndexBuffer::D3DIndexBuffer() :
	m_indexesBuffer( NULL )
{
}

D3DIndexBuffer::~D3DIndexBuffer()
{
	Release(m_indexesBuffer);
}

void D3DIndexBuffer::createBuffer(IRenderer& _renderer, unsigned short _indices[], int _size)
{
	CD3D11_BUFFER_DESC indexesBufferDesc(_size, D3D11_BIND_INDEX_BUFFER);
	D3D11_SUBRESOURCE_DATA indexesData = { 0 };
	indexesData.pSysMem = _indices;

	ID3D11Device *device = static_cast<ID3D11Device*>(_renderer.GetDevice());
	device->CreateBuffer(&indexesBufferDesc, &indexesData, &m_indexesBuffer);
}

void D3DIndexBuffer::setBuffer(IRenderer& _renderer)
{
	ID3D11DeviceContext *context = static_cast<ID3D11DeviceContext*>(_renderer.GetContextDevice());
	context->IASetIndexBuffer(m_indexesBuffer, DXGI_FORMAT_R16_UINT, 0);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}
