#include "FacesEngine.h"
#include "itFaceParser.h"
#include <Windows.h>

#define MAX_FRAME_RATE 120
#define MIN_FRAME_RATE 15
#define UPDATE_INTERVAL (1.0 / MAX_FRAME_RATE)
#define MAX_CYCLES_PER_FRAME (MAX_FRAME_RATE / MIN_FRAME_RATE)

FacesEngine::FacesEngine(itString *_rootPath)
	: m_root(nullptr)
	, m_renderer(nullptr)
	, m_rootPath(_rootPath)
	, m_resourceManager(nullptr)
	, m_lastFrameTime(0.0)
	, m_cyclesLeftOver(0.0)
	, m_currentTime(0.0)
	, m_updateIterations(0.0)
	, m_senderUpdateCallback(nullptr)
	, m_updateCallback(nullptr)
{
}

FacesEngine::~FacesEngine()
{
	if (m_root != nullptr) {
		delete m_root;
	}

	if (m_resourceManager != nullptr) {
		delete m_resourceManager;
		m_resourceManager = nullptr;
	}
}

bool FacesEngine::init(IRenderer *_renderer) {
	m_renderer = _renderer;
	m_resourceManager = new ResourceManager(_renderer);
	m_renderer->SetEngine(this);
	m_renderer->Init();
	//m_renderer->setShaders();

	return true;
}

bool FacesEngine::load(itString *_filename)
{
	if (m_renderer != nullptr) {
		itFaceParser parser(m_renderer);
		parser.load(_filename->c_str());
		parser.parse(&m_root);
	}

	m_root->init(*m_renderer);
	
	return true;
}

void FacesEngine::beginFrame()
{
	m_renderer->BeginFrame();
}

void FacesEngine::render() {
	beginFrame();
	update();
	m_renderer->Draw(*m_root);
}

void FacesEngine::OnUpdate(float _interval) {
	if (m_updateCallback != nullptr) {
		m_updateCallback(m_senderUpdateCallback, _interval);
	}
}

void FacesEngine::SetUpdateCallback(void* _sender, OnUpdateCallback_t _callback) {
	m_senderUpdateCallback = _sender;
	m_updateCallback = _callback;
}

void FacesEngine::update()
{
	m_currentTime = GetTickCount();
	m_updateIterations = ((m_currentTime - m_lastFrameTime) + m_cyclesLeftOver);

	if (m_updateIterations > (MAX_CYCLES_PER_FRAME * UPDATE_INTERVAL)) {
		m_updateIterations = (MAX_CYCLES_PER_FRAME * UPDATE_INTERVAL);
	}

	while (m_updateIterations > UPDATE_INTERVAL) {
		m_updateIterations -= UPDATE_INTERVAL;

		m_renderer->Update(*m_root);
		OnUpdate(UPDATE_INTERVAL);
	}

	m_cyclesLeftOver = m_updateIterations;
	m_lastFrameTime = m_currentTime;
}
