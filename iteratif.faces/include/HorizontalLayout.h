#ifndef HORIZONTALLAYOUT_H_
#define HORIZONTALLAYOUT_H_

//#include "faces.h"
//#include "Container.h"
#include "ILayout.h"
#include "Container.h"

class HorizontalLayout : public ILayout
{
public:
	HorizontalLayout();
	HorizontalLayout(float _gap);
	HorizontalLayout(float _paddingLeft, float _paddingTop);
	HorizontalLayout(float _paddingLeft, float _paddingTop, float _gap);
	virtual void doLayout(Container& _container);
};

#endif; // !HORIZONTALLAYOUT_H_
