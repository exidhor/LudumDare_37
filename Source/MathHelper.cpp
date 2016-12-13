#include <cfloat>
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

unsigned MathHelper::getClosestPoint(sf::Vector2f const& pointToCompare,
									 std::vector<sf::Vector2f> const& points)
{
	float bestSquareDistance = FLT_MAX;
	int bestIndex = -1;

	float currentSquareDistance = 0;

	for(unsigned i = 0; i < points.size(); i++)
	{
		currentSquareDistance = Movement::squareDistance(pointToCompare, points[i]);

		if(currentSquareDistance < bestSquareDistance)
		{
			bestSquareDistance = currentSquareDistance;
			bestIndex = i;
		}
	}

	if(bestIndex == -1)
	{
		std::cerr << "ERROR : best value not found !" << std::endl;
	}

	return bestIndex;
}

sf::Vector2f  MathHelper::rotatePoint(sf::Vector2f const& point,
									  sf::Vector2f const& centerOfRotation,
									  float angleInDegree)
{
	sf::Vector2f resultRotation;

	float offset_x = point.x - centerOfRotation.x;
	float offset_y = point.y - centerOfRotation.y;

	// "rotating a point A around point B by C degrees".

	// A.x' = (A.x-B.x) * cos(C) - (A.y-B.y) * sin(C) + B.x
	resultRotation.x = (float)(offset_x * cos(angleInDegree) - offset_y * sin(angleInDegree)
							   + centerOfRotation.x);

	// A.y' = (A.y-B.y) * cos(C) + (A.x-B.x) * sin(C) + B.y
	resultRotation.y = (float)(offset_y * cos(angleInDegree) + offset_x * sin(angleInDegree)
							   + centerOfRotation.y);

	return resultRotation;
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