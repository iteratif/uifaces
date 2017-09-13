#include "View.h"

TYPE_INFO_DECL(View, Container)

View::View()
	: m_refs() {

}

void View::Initialized() {

}

void View::RegisterElement(const char *_id, VisualElement& _element) {
	m_refs.Set(_id, &_element);
}

VisualElement& View::GetElementById(const char *_id) {
	return *(m_refs.Get(_id));
}