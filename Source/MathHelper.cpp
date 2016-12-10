#include "MathHelper.hpp"

sf::Vector2f MathHelper::abs(sf::Vector2f const& vector)
{
	return sf::Vector2f(fabsf(vector.x), fabsf(vector.y));
}

sf::Vector2f Movement::offset(sf::Vector2f const& start, sf::Vector2f const& end)
{
	return end - start;
}

float Movement::distance(sf::Vector2f const& start, sf::Vector2f const& end)
{
	sf::Vector2f distances = MathHelper::abs(offset(start, end));

	return std::sqrt(distances.x * distances.x + distances.y * distances.y);
}

sf::Vector2f Movement::deplacement(sf::Vector2f const& start, sf::Vector2f const& direction, double speed)
{
	if (speed < 0)
	{
		std::cerr << "Speed < 0 during a call to deplacement" << std::endl;
		return sf::Vector2f(); // no deplacement;
	}

	float distanceValue = distance(start, direction);

	if (distanceValue <= speed)
	{
		return offset(start, direction);
	}

	double ratio = speed / distanceValue;

	return offset(start, direction) * (float)ratio;
}

float Movement::getOrientation(sf::Vector2f const& direction)
{
	return atan(direction.x / direction.y);
}