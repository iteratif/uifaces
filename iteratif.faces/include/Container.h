#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Array.h"
#include "TypeInfo.h"
#include "ILayout.h"
#include <stdlib.h>
//#include "IRenderer.h"
#include "VisualElement.h"

//class VisualElement;
class IRenderer;

//class VisualElement;

class Container : public VisualElement
{
	TYPE_INFO(Container)
public:

	Container();
	~Container();

	virtual void init(IRenderer& renderer);
	virtual void update(IRenderer& _renderer);
	virtual void draw(IRenderer& renderer);

	//virtual void draw(IRenderer& _renderer);

	unsigned int getNumElements()
	{
		return m_elements.size();
	};

	int addElement( VisualElement& p_element );
	VisualElement* getElementAt( int p_index );
	VisualElement* removeElementAt( int p_index );
	int numElements() { return m_elements.size(); }

	void setLayout(ILayout* _layout) 
	{
		m_layout = _layout;
		m_layoutChanged = true;
	}
	void doLayout();

protected:
	void destroy();

	//VisualElement** m_elements;
	Array<VisualElement*>	m_elements;
	int						m_index;
	ILayout*				m_layout;
	bool					m_layoutChanged;
};

#endif; // CONTAINER_H_