#include "Game.h"

#include "cpgf/tween/gtweenlist.h"

Game::Game() {

}

void Game::Initialized() {
	m_engine->SetUpdateCallback(this, &Game::OnUpdate);
}

void Game::OnUpdate(void * _sender, float _interval)
{
	cpgf::GTweenList *manager = cpgf::GTweenList::getInstance();
	manager->tick(_interval*0.5);
}