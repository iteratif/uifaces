#ifndef IMAGE_H_
#define IMAGE_H_

#include "VisualElement.h"
#include "IRenderer.h"

class Image : public VisualElement
{
public:
	Image();
	Image( float p_x, float p_y );
	~Image(void);

	virtual void init(IRenderer& renderer );
	virtual void draw(IRenderer& renderer );

	void setSource(const char *_filename);
	const char* getSource() { return m_filename; }

	int GetTextureID() { return m_textureId; }
	void SetTextureID(int _id) { m_textureId = _id; }

protected:
	int							m_textureId;
	const char*					m_filename;
};

#endif // IMAGE_H_