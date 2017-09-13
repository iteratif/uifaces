#ifndef FACESENGINE_H_
#define FACESENGINE_H_

#include "IRenderer.h"
#include "Container.h"
#include "itString.h"
#include "ResourceManager.h"

typedef  void(*OnUpdateCallback_t)(void *_sender, float _interval);

class FacesEngine {
public:
	FacesEngine(itString *_rootPath);
	~FacesEngine();

	bool			init(IRenderer *_renderer);

	bool			load(itString *_filename);

	itString&		getRootPath() { return *m_rootPath; }

	void			beginFrame();
	void			render();
	void			update();

	void			OnUpdate(float _interval);
	void			SetUpdateCallback(void* _sender, OnUpdateCallback_t _callback);

	IRenderer&		GetRenderer() { return *m_renderer; }
	ResourceManager& GetResourceManager() { return *m_resourceManager;  }
	Container*		GetRoot() { return m_root; }

protected:
	double			m_lastFrameTime;
	double			m_cyclesLeftOver;
	double			m_currentTime;
	double			m_updateIterations;

	ResourceManager	*m_resourceManager;
	itString		*m_rootPath;
	Container		*m_root;
	IRenderer		*m_renderer;

	void				*m_senderUpdateCallback;
	OnUpdateCallback_t	m_updateCallback;
};

#endif // !FACESENGINE_H_
