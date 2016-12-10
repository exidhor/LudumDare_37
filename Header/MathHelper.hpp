#pragma once

#include <cstdint>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#define EPSILON_ANGLE 0.1f

namespace MathHelper
{
	sf::Vector2f abs(sf::Vector2f const& vector);

	bool isColliding(sf::FloatRect const& rect, 
					 sf::Vector2f const& centerCircle,
					 float radius);

	bool contains(sf::Vector2f const& centerCircle, 
				  float radius, 
				  sf::Vector2f const& pointToCheck);
}

namespace Movement
{
	sf::Vector2f offset(sf::Vector2f const& start, sf::Vector2f const& end);

	float distance(sf::Vector2f const& start, sf::Vector2f const& end);

	float squareDistance(sf::Vector2f const& start, sf::Vector2f const& end);

	/**
	* return the deplacement of an object (the vector2f returned has to
	* be add to the position)
	*/
	sf::Vector2f deplacement(sf::Vector2f const& start, sf::Vector2f const& direction, double speed);

	float getOrientation(sf::Vector2f const& direction);

	float clipOutToEpsilon(float value);

	float setToNearest(float minValue, float maxValue, float value);
}