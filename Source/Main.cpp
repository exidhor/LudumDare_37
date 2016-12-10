#include "Game.hpp"

int main()
{
	Game game;

	while (game.windowIsOpen())
	{
		game.gameLoop();
	}

	return 0;
}