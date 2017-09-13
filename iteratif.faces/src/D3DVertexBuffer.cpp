#include "D3DVertexBuffer.h"
#include "faces.h"

D3DVertexBuffer::D3DVertexBuffer() :
	m_vertexBuffer( NULL )
{
}

D3DVertexBuffer::~D3DVertexBuffer()
{
	Release(m_vertexBuffer);
}

void D3DVertexBuffer::createBuffer(IRenderer& renderer, const Vertex vertices[], int size)
{
	// Create our vertex buffer
	CD3D11_BUFFER_DESC vertexBufferDesc( size, D3D11_BIND_VERTEX_BUFFER );
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = vertices;

	ID3D11Device *device = static_cast<ID3D11Device*>(renderer.GetDevice());
	device->CreateBuffer( &vertexBufferDesc, &vertexData, &m_vertexBuffer );
}

void D3DVertexBuffer::setBuffer(IRenderer& renderer)
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	ID3D11DeviceContext *context = static_cast<ID3D11DeviceContext*>(renderer.GetContextDevice());
	context->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
}

void D3DVertexBuffer::update(IRenderer & renderer, const Vertex vertices[], int size)
{
	D3D11_MAPPED_SUBRESOURCE resource;
	ID3D11DeviceContext *context = static_cast<ID3D11DeviceContext*>(renderer.GetContextDevice());
	context->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);
	memcpy(resource.pData, &vertices[0], size);
	context->Unmap(m_vertexBuffer, 0);
}
