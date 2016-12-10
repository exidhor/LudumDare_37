#include "Game.hpp"

int main()
{
	Game game;
	game.Init();

	while (game.windowIsOpen())
	{
		game.gameLoop();
	}

	return 0;
}