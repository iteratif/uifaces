#include "VisualElement.h"

int VisualElement::m_countRef = 0;

TYPE_INFO_DECL(VisualElement, nullptr)

VisualElement::VisualElement() 
	: m_x(0)
	, m_y(0)
	, m_width(0)
	, m_height(0)
	, m_scaleX(1.0)
	, m_scaleY(1.0)
	, m_rotation(0)
	, m_alpha(1.0)
	, m_visible(true)
	, m_includeInLayout(true)
	, m_positionChanged(false)
	, m_rotationChanged(false)
	, m_vertexBuffer(nullptr)
	, m_indexBuffer(nullptr)
	, m_alphaBuffer(nullptr)
	, m_translationMatrix(nullptr)
	, m_rotationMatrix(nullptr)
	, m_scaleMatrix(nullptr)
{
	m_countRef++;
}

VisualElement::~VisualElement(void) {
	m_countRef--;
	if (m_translationMatrix != nullptr) delete m_translationMatrix;
	if (m_rotationMatrix != nullptr) delete m_rotationMatrix;
	if (m_scaleMatrix != nullptr) delete m_scaleMatrix;
}

void VisualElement::init(IRenderer & _renderer) {
	_renderer.CreateMatrix(&m_translationMatrix);
	_renderer.CreateMatrix(&m_rotationMatrix);
	_renderer.CreateMatrix(&m_scaleMatrix);

	float mWidth = m_width * 0.5;
	float mHeight = m_height * 0.5;
	
	Vertex vertices[] = {
		{ - mWidth, - mHeight, 0.0, 0.0 },
		{ mWidth, - mHeight, 1.0, 0.0 },
		{ mWidth, mHeight, 1.0, 1.0 },
		{ - mWidth, mHeight, 0.0, 1.0 }
	};

	unsigned short indexes[6] = {
		0, 1, 2,
		2, 3, 0
	};

	m_vertexBuffer = _renderer.CreateVertexBuffer(vertices, sizeof(Vertex) * 4);
	m_indexBuffer = _renderer.CreateIndexBuffer(indexes, sizeof(indexes));
	m_alphaBuffer = _renderer.CreateBuffer();
	Initialized();
}

void VisualElement::update(IRenderer& _renderer) {
}

void VisualElement::setTransforms(IRenderer& _renderer) {
	m_scaleMatrix->Scale(m_scaleX, m_scaleY, 1.0);
	_renderer.PushTransform(m_scaleMatrix);

	m_rotationMatrix->RotationZ(m_rotation);
	_renderer.PushTransform(m_rotationMatrix);
	
	m_translationMatrix->Translate(m_x, m_y, 0.0);
	_renderer.PushTransform(m_translationMatrix);
}

void VisualElement::clearTransformations(IRenderer& _renderer) {
	_renderer.PopTransform(m_translationMatrix);
	_renderer.PopTransform(m_rotationMatrix);
	_renderer.PopTransform(m_scaleMatrix);
}

void VisualElement::draw(IRenderer& _renderer) {
	m_alphaBuffer->setBuffer(_renderer,&m_alpha);

	// Bind out mesh shaders
	m_vertexBuffer->setBuffer(_renderer);

	// Define our vertices
	m_indexBuffer->setBuffer(_renderer);

	// Draw
	_renderer.DrawIndexed(6, 0, 0);
}

void VisualElement::setX(float _value) {
	if (_value == m_x) return;

	m_x = _value;
	m_positionChanged = true;
}

void VisualElement::setY(float _value) {
	if (_value == m_y) return;

	m_y = _value;
	m_positionChanged = true;
}

void VisualElement::setWidth(float _value) {
	if (m_width == 0 || _value == 0) {
		m_scaleX = 1.0;
	}
	else {
		m_scaleX = _value / m_width;
	}

	m_width = _value;
}

void VisualElement::setHeight(float _value) {
	if (m_height == 0 || _value == 0) {
		m_scaleY = 1.0;
	}
	else {
		m_scaleY = _value / m_height;
	}

	m_height = _value;
}

void VisualElement::setScaleX(float _value) {
	m_width = m_width * _value;
	m_scaleX = _value;
}

void VisualElement::setScaleY(float _value) {
	m_height = m_height * _value;
	m_scaleY = _value;
}

void VisualElement::setAlpha(float _value)
{
	m_alpha = _value;
}

float VisualElement::getRotation()
{
	return m_rotation;
}

void VisualElement::setRotation(float _value)
{
	m_rotation = _value;
	m_rotationChanged = true;
}
