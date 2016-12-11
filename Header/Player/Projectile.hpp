#pragma once

#include "Graphics/Drawable.hpp"
#include "Behavior/Movable.hpp"
#include "World.hpp"

class Projectile : public Movable
{
public :
	Projectile(float speed);
	virtual ~Projectile() {};

	virtual sf::Vector2f move(sf::Vector2f const& position, float speed) = 0;
	void update(double time);
    virtual void killDemoniacObject(const World world) = 0;

	bool toRemove() const;

	Drawable & getDrawable();

private:
	Drawable m_drawable;
	float m_speed;

	double m_timeTreshold;
	double m_timeElapsed;
	bool m_toRemove;
};