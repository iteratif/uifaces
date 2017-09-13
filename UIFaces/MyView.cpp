#include "MyView.h"
#include "faces.h"

#include "cpgf/tween/gtweenlist.h"
#include "cpgf/accessor/gaccessor.h"
#include "cpgf/tween/easing/elastic.h"
#include "cpgf/tween/easing/bounce.h"

MyView::MyView() {

}

void MyView::Initialized() {
	/*Container *cp = static_cast<Container*>(this->getElementAt(0));
	Container *cp2 = static_cast<Container*>(cp->getElementAt(0));

	cpgf::GTweenList *manager = cpgf::GTweenList::getInstance();
	cpgf::GTween & tween = manager->tween()
		.yoyo(true)
		.repeat(5)
		.duration(10.0f)
		.ease(cpgf::BounceEase::easeOut())
		.target(cpgf::createAccessor(cp->getElementAt(2), GET_PROPERTY(VisualElement, Y), SET_PROPERTY(VisualElement, Y)), 400)
		.target(cpgf::createAccessor(cp->getElementAt(2), GET_PROPERTY(VisualElement, Rotation), SET_PROPERTY(VisualElement, Rotation)), 360);

	manager->tween()
		.duration(10.0f)
		.repeat(5)
		.target(cpgf::createAccessor(cp2->getElementAt(0), GET_PROPERTY(VisualElement, Rotation), SET_PROPERTY(VisualElement, Rotation)), 360);*/
}

