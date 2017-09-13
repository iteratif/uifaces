#ifndef VIEW_H_
#define VIEW_H_

#include "Container.h"
#include "TypeInfo.h"
#include "HashMap.h"

class View : public Container {
	TYPE_INFO(View)
public:

	View();
	virtual void Initialized() override;
	void RegisterElement(const char *_id, VisualElement& _element);
	VisualElement& GetElementById(const char *_id);

private:
	iteratif::HashMap<VisualElement*> m_refs;
};

#endif // !VIEW_H_

