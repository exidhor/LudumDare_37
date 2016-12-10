#include "Game.hpp"

int main()
{
	Game game;
	game.Init();

	sf::Clock clock;
	sf::Time time;
	double timeElasped;

	while (game.windowIsOpen())
	{
		time = clock.getElapsedTime();
		timeElasped = time.asSeconds();
		clock.restart();

		game.gameLoop();
	}

	return 0;
}
