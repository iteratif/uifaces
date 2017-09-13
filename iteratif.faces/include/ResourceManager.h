#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include "IRenderer.h"
#include "itString.h"
#include "Array.h"

enum class ResourceType
{
	IMAGE
};

class Texture
{
public:
	virtual ~Texture() {}
	float			Width;
	float			Height;
};

class ResourceManager
{
public:
	ResourceManager(IRenderer *_renderer);
	~ResourceManager();
	int loadTexture(itString _path);
	Texture* GetTextureById(int _id);

private:
	IRenderer *m_renderer;
	Array<Texture*> m_resources;
};

#endif // !RESOURCE_MANAGER_H_
