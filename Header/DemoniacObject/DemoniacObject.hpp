#pragma once

#include "Behavior/Unit.hpp"
#include "Behavior/PathFollower.hpp"
#include "Behavior/Shooter.hpp"


class DemoniacObject : public Unit, public PathFollower, public Shooter
{
public :
	DemoniacObject(sf::Vector2f const& startPosition, int life, int speed)
        : Unit(life),
          PathFollower(startPosition),
          Shooter(),
          m_speed(speed)
    {
        // nothing
    }

private :
	int m_speed;
};
