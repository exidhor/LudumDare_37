#pragma once
#include <SFML/System.hpp>

class Movable
{
public :
	virtual void move(sf::Vector2f const& position, float speed) = 0;
};
