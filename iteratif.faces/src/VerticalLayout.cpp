#include "VerticalLayout.h"
#include "VisualElement.h"

VerticalLayout::VerticalLayout()
{
	init(10, 10, 5);
}

VerticalLayout::VerticalLayout(float _gap)
{
	init(10, 10, _gap);
}

VerticalLayout::VerticalLayout(float _paddingLeft, float _paddingTop)
{
	init(_paddingLeft, _paddingTop, 5);
}

VerticalLayout::VerticalLayout(float _paddingLeft, float _paddingTop, float _gap)
{
	init(_paddingLeft, _paddingTop, _gap);
}

void VerticalLayout::doLayout( Container& _container)
{
	float xPos = m_paddingLeft;
	float yPos = m_paddingTop;
	VisualElement *element = NULL;
	int numElements = _container.numElements();

	for (int i = 0; i < numElements; i++)
	{
		element = _container.getElementAt(i);
		if (element->isIncludeInLayout()) {
			element->setX(xPos);
			element->setY(yPos);
			yPos += element->getHeight() + m_gap;
		}
	}
}

