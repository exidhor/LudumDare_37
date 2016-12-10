#pragma once
#include <SFML/System.hpp>

class Movable
{
public :
	virtual sf::Vector2f move(sf::Vector2f const& position, float speed) = 0;
};
