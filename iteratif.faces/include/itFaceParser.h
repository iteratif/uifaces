#ifndef ITFACEPARSER_H_
#define ITFACEPARSER_H_

#include "tinyxml2.h"
#include "Array.h"
#include "ILayout.h"
#include "VisualElement.h"
#include "Container.h"
#include "View.h"

struct Property {
	Property(const char *_name, float _value)
	: Name(_name)
	, Value(_value) {

	}
	const char *Name;
	float Value;
};

class itFaceParser {
public:
	itFaceParser(IRenderer *_renderer);
	~itFaceParser();

	int load(const char *_filename);
	int parse(Container **_container);
private:
	void parseAttributes(tinyxml2::XMLElement *_element, VisualElement *_visual, View& _view);
	void parseNodes(tinyxml2::XMLElement *_element, Container *_container, View& _view);
	void parseLayout(tinyxml2::XMLElement *_element, Container *_container);
	void parseLayoutAttributes(tinyxml2::XMLElement *_element, ILayout *_layout);
	void parseView(tinyxml2::XMLElement *_element, Container **_container);

	void parseTweens(tinyxml2::XMLElement *_element, tinyxml2::XMLElement *_root);
	void parseTween(tinyxml2::XMLElement *_element, View& _view);
	//void parsePropertiesTween(tinyxml2::XMLElement *_element, Array<Property*> *_properties);

	IRenderer				*m_renderer;
	tinyxml2::XMLDocument	*m_document;
};

#endif // !ITFACEPARSER_H_
