#pragma once

#include "Graphics/Drawable.hpp"
#include "Behavior/Movable.hpp"

class Projectile : public Movable
{
public :
	Projectile(float speed, int damage, double timeBetweenSwap);

	virtual sf::Vector2f move(sf::Vector2f const& position, float speed) = 0;
	void update(double time);

	float getDamage() const;

	Drawable & getDrawable();

private:
	Drawable m_drawable;
	float m_speed;
	int m_damage;
	double m_elapsedSinceLastSpriteSwap;
	double m_spriteSwapTreshold;
};