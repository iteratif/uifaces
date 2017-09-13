#include "AlphaBuffer.h"
#include "faces.h"

AlphaBuffer::AlphaBuffer()
	: m_buffer(NULL) {
}

AlphaBuffer::~AlphaBuffer() {
	Release(m_buffer);
}

void AlphaBuffer::createBuffer(IRenderer& _renderer) {
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	bufferDesc.ByteWidth = sizeof(AlphaBufferType);
	bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	ID3D11Device *device = static_cast<ID3D11Device*>(_renderer.GetDevice());
	device->CreateBuffer(&bufferDesc, NULL, &m_buffer);
}

void AlphaBuffer::setBuffer(IRenderer& _renderer, void *_value) {
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	AlphaBufferType *alphaType;
	ID3D11DeviceContext *context = static_cast<ID3D11DeviceContext*>(_renderer.GetContextDevice());
	context->Map(m_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	alphaType = (AlphaBufferType*)mappedResource.pData;
	alphaType->alpha = *(float*)(_value);
	context->Unmap(m_buffer, 0);
	context->PSSetConstantBuffers(0, 1, &m_buffer);
}
