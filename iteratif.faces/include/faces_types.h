#ifndef FACES_TYPES_H_
#define FACES_TYPES_H_

/*#ifdef _GL_
#define itMatrix mat4

inline itMatrix itMatrixIdentity() {
	return nullptr;
}
#else
#define itMatrix XMMATRIX

inline itMatrix itMatrixIdentity() {
	return XMMatrixIdentity();
}

#endif // _DX_*/

#include <DirectXMath.h>

struct Vertex {
	float x, y;
	//float r, g, b;
	float u, v;
};

struct MatrixBufferType {
	DirectX::XMFLOAT4X4 trans;
};

struct ScreenBufferType {
	DirectX::XMFLOAT4 screen;
};

struct TranfBufferType {
	DirectX::XMFLOAT4X4 world;
};

struct AlphaBufferType {
	float alpha;
	DirectX::XMFLOAT3 padding;
};

typedef struct BoundingBox_tag {
	float x;
	float y;
	float width;
	float height;
} BoundingBox;

#endif; // FACES_TYPES_H_