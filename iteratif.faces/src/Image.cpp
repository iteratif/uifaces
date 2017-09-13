#include "Image.h"
#include <tchar.h>

Image::Image()
	: m_filename(nullptr) {

}

Image::Image(float _x, float _y)
	: m_filename(nullptr) {
	setX(_x);
	setY(_y);
}

Image::~Image(void) {
	
}

void Image::setSource(const char *_filename)
{
	const int size = strlen(_filename);
	char *filename = new char[size + 1];
	strncpy(filename, _filename, size);
	filename[size] = '\0';
	m_filename = filename;
}

void Image::init(IRenderer & renderer)
{
	VisualElement::init(renderer);
}

void Image::draw(IRenderer& renderer)
{
	renderer.SetTexture(GetTextureID());
	VisualElement::draw(renderer);
}
