#ifndef __GAME_HPP
#define __GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();

	void gameLoop();

	void handleInput();

	void draw();

	bool windowIsOpen() const;

private:
	sf::RenderWindow m_window;
	sf::CircleShape m_shape;
};

#endif // __GAME_HPP