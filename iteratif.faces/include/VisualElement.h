#ifndef VISUALELEMENT_H_
#define VISUALELEMENT_H_

#include "Array.h"
#include "itMatrix.h"
#include "IBuffer.h"
#include "IVertexBuffer.h"
#include "IIndexBuffer.h"
#include "TypeInfo.h"
#include "faces_types.h"
#include "IRenderer.h"

//class IRenderer;

class VisualElement {
	TYPE_INFO(VisualElement)
public:

	VisualElement();
	virtual ~VisualElement(void);

	virtual void init(IRenderer& _renderer);
	virtual void Initialized() {}
	virtual void update(IRenderer& _renderer);
	virtual void setTransforms(IRenderer& _renderer);
	virtual void clearTransformations(IRenderer& _renderer);
	virtual void draw(IRenderer& _renderer);

	float getX() const			{	return m_x;			}
	float getY() const			{	return m_y;			}
	float getWidth() const		{	return m_width;		}
	float getHeight() const		{	return m_height;	}
	float getScaleX() const		{	return m_scaleX;	}
	float getScaleY() const		{	return m_scaleY;	}
	float getAlpha() const		{	return m_alpha;		}

	void setX(float _value);
	void setY(float _value);
	void setWidth(float _value);
	void setHeight(float _value);
	void setScaleX(float _value);
	void setScaleY(float _value);
	void setAlpha(float _value);

	bool isVisible() { return m_visible;  }
	void setVisible(bool _value) { m_visible = _value; }

	bool isIncludeInLayout() { return m_includeInLayout; }
	void setIncludeInLayout(bool _value) { m_includeInLayout = _value; }

	float getRotation();
	void setRotation(float _value);

	BoundingBox		boundingBox;
	Array<Vertex*>	vertices;
	
private:
	static int	m_countRef;

protected:
	float			m_x;
	float			m_y;
	float			m_width;
	float			m_height;
	float			m_scaleX;
	float			m_scaleY;
	float			m_rotation;
	float			m_alpha;
	bool			m_visible;
	bool			m_includeInLayout;
	bool			m_positionChanged;
	bool			m_rotationChanged;

	IMatrix			*m_translationMatrix;
	IMatrix			*m_rotationMatrix;
	IMatrix			*m_scaleMatrix;

	IBuffer			*m_alphaBuffer;
	IVertexBuffer	*m_vertexBuffer;
	IIndexBuffer	*m_indexBuffer;

};

#endif // VISUALELEMENT_H_
