//#include "VisualElement.h"
#include "Container.h"
#include "IRenderer.h"
#include <string.h>

TYPE_INFO_DECL(Container,VisualElement)

Container::Container() : 
	/*VisualElement(),*/ 
	m_index(0), 
	m_elements(), 
	m_layout(nullptr),
	m_layoutChanged(true)
{
	
}

Container::~Container()
{
	destroy();
}

/*void Container::draw(IRenderer & _renderer)
{
}*/

void Container::doLayout()
{
	if (m_layout != nullptr)
	{
		if( m_layoutChanged )
		{ 
			m_layoutChanged = false;
			m_layout->doLayout(*this);
		}
	}
}

void Container::destroy()
{
	itType *type = nullptr;
	VisualElement *element = nullptr;
	int numItems = m_elements.size();
	for (int i = 0; i < numItems; i++) {
		element = m_elements.get(i);
		type = element->getType();
		if (strcmp(Container::type.classname, type->classname) == 0) {
			Container *container = static_cast<Container*>(element);
			delete container;
		}
		else if (element != nullptr) {
			delete element;
		}
	}
}

void Container::init(IRenderer & _renderer)
{
	VisualElement *item = nullptr;
	_renderer.CreateMatrix(&m_translationMatrix);
	_renderer.CreateMatrix(&m_rotationMatrix);
	_renderer.CreateMatrix(&m_scaleMatrix);
	int numItems = m_elements.size();
	for (int i = 0; i < numItems; i++)
	{
		item = m_elements.get(i);
		item->init(_renderer);
	}
	Initialized();
}

void Container::draw(IRenderer& _renderer) {
	VisualElement *item = nullptr;
	int numItems = m_elements.size();
	for (int i = 0; i < numItems; i++)
	{
		item = m_elements.get(i);
		item->setTransforms(_renderer);
		setTransforms(_renderer);
		if (item->isVisible()) {
			item->draw(_renderer);
		}
		clearTransformations(_renderer);
		item->clearTransformations(_renderer);
	}
}


void Container::update(IRenderer& _renderer)
{
	doLayout();
	VisualElement *item = nullptr;
	int numItems = m_elements.size();
	for (int i = 0; i < numItems; i++)
	{
		item = m_elements.get(i);
		item->update(_renderer);
	}
}

int Container::addElement( VisualElement& p_element )
{
	return m_elements.add(&p_element);
}

VisualElement* Container::getElementAt( int p_index )
{
	return m_elements.get( p_index );
}

VisualElement* Container::removeElementAt( int p_index )
{
	return nullptr;
}
