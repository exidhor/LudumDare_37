#pragma once

#include <SFML/System.hpp>

#include "MathHelper.hpp"
#include "World.hpp"
#include "Graphics/Drawable.hpp"
#include "Player/Projectile.hpp"

class Turret
{
public :
	Turret(float m_timeBetWeenShoot, float targetingRange, float shootingRange);

    void update(double time, const World world);
    Projectile* shoot();

    virtual Projectile *getProjectile(sf::Vector2f const &target) = 0;

	virtual std::vector<Drawable*> getDrawables();

	Drawable & getDrawable();

protected:
	Drawable m_drawable;

    float m_timeUntilShoot;
    bool m_isTimeToShoot;
    bool m_hasATarget;
    sf::Vector2f m_nearestTargetPosition;

    float m_timeBetweenShoot;
    float m_targetingRange;
    float m_shootingRange;
};