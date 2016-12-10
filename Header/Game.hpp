#ifndef __GAME_HPP
#define __GAME_HPP

#include <SFML/Graphics.hpp>
#include <Player/Player.hpp>

class Game
{
public:
	Game();

    /// \brief Initialize the game class
	void Init();

	void gameLoop(double time);

	void handleInput(double elapsed);

	void draw();

	bool windowIsOpen() const;

private:
	sf::RenderWindow    m_window;
	sf::CircleShape     m_shape;
    Player*             m_player;
};

#endif // __GAME_HPP

// monstres ou sont ils geré