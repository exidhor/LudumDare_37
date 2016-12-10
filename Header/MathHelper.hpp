#pragma once
#include <SFML/System.hpp>

namespace MathHelper
{
	/**
	 * return the deplacement of an object (the vector2f returned has to
	 * be add to the position)
	 */
	sf::Vector2f moveEntity(sf::Vector2f const& direction, float speed);
}