#include "Game.hpp"

int main()
{
	Game game;
    game.Init();

	sf::Clock clock;
	sf::Time time;
	double timeElapsed;

	while (game.windowIsOpen())
	{
		time = clock.getElapsedTime();
		timeElapsed = time.asSeconds();
		clock.restart();

		game.gameLoop(timeElapsed);
	}

	return 0;
}
