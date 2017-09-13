#include "ResourceManager.h"

ResourceManager::ResourceManager(IRenderer *_renderer)
	: m_renderer(_renderer)
	, m_resources()
{

}

ResourceManager::~ResourceManager() {
	int size = m_resources.size();
	for (int i = 0; i < size; i++) {
		delete m_resources.get(i);
	}
}

int ResourceManager::loadTexture(itString _path)
{
	int id = -1;
	Texture *t = nullptr;
	m_renderer->CreateTexture(_path, &t);
	id = m_resources.add(t);
	
	return id;
}

Texture* ResourceManager::GetTextureById(int _id)
{
	//assert(_id < 0 && _id >= m_resources.size());

	return m_resources.get(_id);
}