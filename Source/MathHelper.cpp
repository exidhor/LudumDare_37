#include "MathHelper.hpp"

sf::Vector2f MathHelper::abs(sf::Vector2f const& vector)
{
	return sf::Vector2f(fabsf(vector.x), fabsf(vector.y));
}

bool MathHelper::isColliding(sf::FloatRect const& rect,
							 sf::Vector2f const& centerCircle,
							 float radius)
{
	sf::FloatRect globalBoundsCircle;
	globalBoundsCircle.left = centerCircle.x - radius;
	globalBoundsCircle.top = centerCircle.y - radius;
	globalBoundsCircle.width = 2 * radius;
	globalBoundsCircle.height = 2 * radius;

	sf::FloatRect intersections;

	bool isIn = rect.intersects(globalBoundsCircle, intersections);

	if (isIn)
		return true;

	// left/top
	isIn = contains(centerCircle, radius, sf::Vector2f(intersections.left, 
					                                   intersections.top));

	if (isIn)
		return true;

	// right/top
	isIn = contains(centerCircle, radius, sf::Vector2f(intersections.left + intersections.width, 
		                                               intersections.top));

	if (isIn)
		return true;

	// right/bot
	isIn = contains(centerCircle, radius, sf::Vector2f(intersections.left + intersections.width,
					                                   intersections.top + intersections.height));

	if (isIn)
		return true;

	// left/bot
	isIn = contains(centerCircle, radius, sf::Vector2f(intersections.left, 
					                                   intersections.top + intersections.height));

	return isIn;
}

bool MathHelper::contains(sf::Vector2f const& centerCircle,
						  float radius,
						  sf::Vector2f const& pointToCheck)
{
	return Movement::squareDistance(centerCircle, pointToCheck) < radius * radius;
}

sf::Vector2f Movement::offset(sf::Vector2f const& start, sf::Vector2f const& end)
{
	return end - start;
}

float Movement::squareDistance(sf::Vector2f const& start, sf::Vector2f const& end)
{
	sf::Vector2f distances = MathHelper::abs(offset(start, end));

	return distances.x * distances.x + distances.y * distances.y;
}

float Movement::distance(sf::Vector2f const& start, sf::Vector2f const& end)
{
	return sqrt(squareDistance(start, end));
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
	float directionX = clipOutToEpsilon(direction.x);
	float directionY = clipOutToEpsilon(direction.y);

	return atan2(directionX, -directionY);
}

float Movement::clipOutToEpsilon(float value)
{
	if (-EPSILON_ANGLE < value && value < EPSILON_ANGLE)
		return setToNearest(-EPSILON_ANGLE, EPSILON_ANGLE, value);

	return value;
}

float Movement::setToNearest(float minValue, float maxValue, float value)
{
	float distToMin = fabsf(minValue - value);
	float distToMax = fabsf(maxValue - value);

	if (distToMin < distToMax)
		return minValue;

	else
		return maxValue;
}