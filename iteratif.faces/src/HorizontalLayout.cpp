#include "HorizontalLayout.h"
#include "VisualElement.h"

HorizontalLayout::HorizontalLayout()
{
	init(10.0, 10.0, 5.0);
}

HorizontalLayout::HorizontalLayout(float _gap)
{
	init(10.0, 10.0, _gap);
}

HorizontalLayout::HorizontalLayout(float _paddingLeft, float _paddingTop)
{
	init(_paddingLeft, _paddingTop, 5.0);
}

HorizontalLayout::HorizontalLayout(float _paddingLeft, float _paddingTop, float _gap)
{
	init(_paddingLeft, _paddingTop, _gap);
}

void HorizontalLayout::doLayout(Container & _container)
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
			xPos += element->getWidth() + m_gap;
		}
	}
}
