#include "tinyxml2.h"
#include "cpgf/tween/gtweenlist.h"
#include "cpgf/accessor/gaccessor.h"
#include "cpgf/tween/easing/elastic.h"
#include "cpgf/tween/easing/bounce.h"
#include "itFaceParser.h"
#include "Image.h"
#include "HorizontalLayout.h"
#include "VerticalLayout.h"
#include "FacesEngine.h"
#include "ClassFactory.h"
#include "View.h"
#include "TypeInfo.h"

#define CONTAINER_TAG				"container"
#define IMAGE_TAG					"image"
#define LAYOUT_TAG					"layout"

#define TWEENS_TAG					"tweens"
#define TWEEN_TAG					"tween"
#define PROPERTY_DURATION			"duration"
#define PROPERTY_REPEAT				"repeat"
#define PROPERTY_YOYO				"yoyo"
#define PROPERTY_TARGET				"target"
#define PROPERTY_EASE				"ease"
#define PROPERTY_TAG				"property"
#define PROPERTY_NAME				"name"
#define PROPERTY_TO					"to"

#define HORIZONTAL_TAG				"horizontal"
#define VERTICAL_TAG				"vertical"

#define PROPERTY_CLASS				"class"
#define PROPERTY_ID					"id"
#define PROPERTY_GAP				"gap"
#define PROPERTY_ROTATION			"rotation"
#define PROPERTY_X					"x"
#define PROPERTY_Y					"y"
#define PROPERTY_ALPHA				"alpha"
#define PROPERTY_SCALE_X			"scaleX"
#define PROPERTY_SCALE_Y			"scaleY"
#define PROPERTY_VISIBLE			"visible"
#define PROPERTY_INCLUDEINLAYOUT	"includeInLayout"

#define PROPERTY_SOURCE				"source"

using namespace tinyxml2;
using namespace cpgf;

itFaceParser::itFaceParser(IRenderer *_renderer) 
	: m_renderer(_renderer)
	, m_document(nullptr) {
}

itFaceParser::~itFaceParser() {
	delete m_document;
}

int itFaceParser::load(const char *_filename) {
	m_document = new tinyxml2::XMLDocument();
	m_document->LoadFile(_filename);
	return 0;
}

int itFaceParser::parse(Container **_container) {
	XMLElement* elt = m_document->FirstChildElement();
	parseView(elt, _container);
	return 0;
}

void itFaceParser::parseLayoutAttributes(XMLElement *_element, ILayout *_layout) {
	const XMLAttribute *attr = _element->FirstAttribute();
	if (attr != nullptr) {
		do {
			if (strcmp(PROPERTY_GAP, attr->Name()) == 0) {
				_layout->setGap(attr->FloatValue());
			}
		} while ((attr = attr->Next()) != nullptr);
	}
}

void itFaceParser::parseAttributes(XMLElement *_element, VisualElement *_visual, View& _view) {
	const XMLAttribute *attr = _element->FirstAttribute();
	if (attr != nullptr) {
		do {
			if (strcmp(PROPERTY_ID, attr->Name()) == 0) {
				// @TODO Add references into dictionary with id as key into View class
			}
			else if (strcmp(PROPERTY_ROTATION, attr->Name()) == 0) {
				_visual->setRotation(attr->FloatValue());
			}
			else if (strcmp(PROPERTY_X, attr->Name()) == 0) {
				_visual->setX(attr->FloatValue());
			}
			else if (strcmp(PROPERTY_Y, attr->Name()) == 0) {
				_visual->setY(attr->FloatValue());
			}
			else if (strcmp(PROPERTY_ALPHA, attr->Name()) == 0) {
				_visual->setAlpha(attr->FloatValue());
			}
			else if (strcmp(PROPERTY_SCALE_X, attr->Name()) == 0) {
				_visual->setScaleX(attr->FloatValue());
			}
			else if (strcmp(PROPERTY_SCALE_Y, attr->Name()) == 0) {
				_visual->setScaleY(attr->FloatValue());
			}
			else if (strcmp(PROPERTY_VISIBLE, attr->Name()) == 0) {
				_visual->setVisible(attr->BoolValue());
			}
			else if (strcmp(PROPERTY_INCLUDEINLAYOUT, attr->Name()) == 0) {
				_visual->setIncludeInLayout(attr->BoolValue());
			}
		} while ((attr = attr->Next()) != nullptr);
	}
} 

void itFaceParser::parseNodes(XMLElement *_element, Container *_container, View& _view) {
	XMLElement *elt = _element->FirstChildElement();
	if (elt != nullptr) {
		do {
			if (strcmp(CONTAINER_TAG, elt->Value()) == 0) {
				Container *container = new Container();
				parseAttributes(elt, container, _view);
				parseNodes(elt, container, _view);
				_container->addElement(*container);
			}
			else if (strcmp(IMAGE_TAG, elt->Value()) == 0) {
				Image *image = new Image();

				const char *value = elt->Attribute(PROPERTY_SOURCE);
				FacesEngine& engine = m_renderer->GetEngine();
				ResourceManager& manager = engine.GetResourceManager();
				int id = manager.loadTexture(value);
				image->SetTextureID(id);
				Texture* texture = manager.GetTextureById(id);
				image->setWidth(texture->Width);
				image->setHeight(texture->Height);

				parseAttributes(elt, image, _view);
				_container->addElement(*image);
			}
			else if (strcmp(LAYOUT_TAG, elt->Value()) == 0) {
				parseLayout(elt, _container);
			}
			else if (strcmp(TWEENS_TAG, elt->Value()) == 0) {
				parseTweens(elt, _element);
			}
		} while ((elt = elt->NextSiblingElement()) != nullptr);
	}
}

void itFaceParser::parseLayout(XMLElement * _element, Container *_container)
{
	XMLElement *eltLayout = _element->FirstChildElement();
	if (strcmp(HORIZONTAL_TAG, eltLayout->Value()) == 0) {
		HorizontalLayout *layout = new HorizontalLayout();
		_container->setLayout(layout);
		parseLayoutAttributes(eltLayout, layout);
	}
	else if (strcmp(VERTICAL_TAG, eltLayout->Value()) == 0) {
		VerticalLayout *layout = new VerticalLayout();
		_container->setLayout(layout);
		parseLayoutAttributes(eltLayout, layout);
	}
}

void itFaceParser::parseView(XMLElement *_element, Container **_container) {
	View *view = nullptr;
	const XMLAttribute *attr = _element->FirstAttribute();
	if (attr != nullptr) {
		if (strcmp(attr->Name(), PROPERTY_CLASS) == 0) {
			const char *_value = attr->Value();
			view = (View*) INSTANCE_VIEW(_value);
		}
	}
	else {
		view = new View();
	}
	parseNodes(_element, view, *view);
	*_container = view;
}

void itFaceParser::parseTweens(XMLElement *_element, XMLElement *_root) {
	XMLElement *elt = _element->FirstChildElement();
	if (elt != nullptr) {
		do {
			if (strcmp(TWEEN_TAG, elt->Value()) == 0) {
				//parseTween(elt);
			}
		} while ((elt = elt->NextSiblingElement()) != nullptr);
	}
}

void itFaceParser::parseTween(XMLElement *_element, View& _view) {
	/*const XMLAttribute *attr = _element->FirstAttribute();
	GTweenList *manager = GTweenList::getInstance();
	GTween& tween = manager->tween();
	if (attr != nullptr) {
		do {
			if (strcmp(attr->Name(), PROPERTY_DURATION) == 0) {
				tween.duration(attr->FloatValue());
			}
			else if (strcmp(attr->Name(), PROPERTY_REPEAT) == 0) {
				tween.repeat(attr->FloatValue());
			}
			else if (strcmp(attr->Name(), PROPERTY_YOYO) == 0) {
				tween.yoyo(attr->BoolValue());
			}
			else if (strcmp(attr->Name(),PROPERTY_TARGET) == 0 )
			{
				const char *_target = attr->Value();
				Array<Property*> properties;
				XMLElement *elt = _element->FirstChildElement();
				if (elt != nullptr) {
					Property *property = nullptr;
					int lenght = properties.size();
					parsePropertiesTween(elt, &properties);
					for (int i = 0; i < lenght; i++) {
						property = properties.get(i);
						if (property != nullptr) {
							const char *name = property->Name;
							tween.target(createAccessor(_view.GetElementById(_target), GET_PROPERTY(VisualElement, name), SET_PROPERTY(VisualElement, name)), property->Value);
						}
					}
				}
			}
		} while ((attr = attr->Next()) != nullptr);
	}*/
}

