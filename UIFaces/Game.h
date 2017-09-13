#ifndef GAME_H_
#define GAME_H_

#include "itGame.h"

class Game : public itGame {
public:
	Game();
	void Initialized() override;
	static void OnUpdate(void *_sender, float _interval);
};

#endif // !GAME_H_

