#ifndef MYVIEW_H_
#define MYVIEW_H_

#include "View.h"

class MyView : public View {
public:
	MyView();

	virtual void Initialized() override;
};

#endif // !MYVIEW_H_

