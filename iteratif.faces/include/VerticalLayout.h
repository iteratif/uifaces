#ifndef VERTICALLAYOUT_H_
#define VERTICALLAYOUT_H_

//#include "faces.h"
#include "ILayout.h"
#include "Container.h"

class VerticalLayout : public ILayout
{
public:
	VerticalLayout();
	VerticalLayout(float _gap);
	VerticalLayout(float _paddingLeft, float _paddingTop);
	VerticalLayout(float _paddingLeft, float _paddingTop, float _gap);
	virtual void doLayout(Container& _container);
};

#endif // !VERTICALLAYOUT_H_
