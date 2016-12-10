#pragma once

#include <cstdint>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

namespace MathHelper
{
	sf::Vector2f abs(sf::Vector2f const& vector);
}

namespace Movement
{
	sf::Vector2f offset(sf::Vector2f const& start, sf::Vector2f const& end);

	float distance(sf::Vector2f const& start, sf::Vector2f const& end);

	/**
	* return the deplacement of an object (the vector2f returned has to
	* be add to the position)
	*/
	sf::Vector2f deplacement(sf::Vector2f const& start, sf::Vector2f const& direction, double speed);
}