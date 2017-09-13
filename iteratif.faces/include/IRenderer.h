#ifndef IRENDERER_H_
#define IRENDERER_H_

#include "faces_types.h"

//#include "VisualElement.h"
#include "itMatrix.h"
//#include "FacesEngine.h"
#include "IBuffer.h"
#include "IVertexBuffer.h"
#include "IIndexBuffer.h"
//#include "ResourceManager.h"

class FacesEngine;
class VisualElement;
class Texture;

class IRenderer
{
public:
	virtual bool Init() = 0;
	virtual void BeginFrame() = 0;
	virtual void Update(VisualElement& _element) = 0;
	virtual void Draw(VisualElement& _element) = 0;
	virtual void CreateMatrix(IMatrix **_matrix) = 0;

	virtual IVertexBuffer* CreateVertexBuffer(Vertex vertices[], int size) = 0;
	virtual IIndexBuffer* CreateIndexBuffer(unsigned short indices[], int size) = 0;
	virtual IBuffer* CreateBuffer() = 0;
	virtual void CreateTexture(const char *_filename, Texture **_texture) = 0;
	virtual void SetTexture(int _id) = 0;

	virtual void DrawIndexed(unsigned int indexCount, unsigned int startIndexLocation, unsigned int baseVertexLocation) = 0;

	virtual void* GetDevice() const = 0;
	virtual void* GetContextDevice() const = 0;

	virtual void PushTransform(IMatrix *_world) = 0;
	virtual void PopTransform(IMatrix *_world) = 0;

	void SetEngine(FacesEngine *_engine) {
		m_engine = _engine;
	}

	FacesEngine& GetEngine() { return *m_engine; }

protected:
	FacesEngine	*m_engine;
};

#endif // !IRENDERER_H_

