#pragma once
#include "Behavior/Movable.hpp"

class Projectile : public Movable
{
public :
	Projectile();

	virtual sf::Vector2f move(sf::Vector2f const& position, float speed);

private :

};