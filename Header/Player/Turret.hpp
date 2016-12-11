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
    Projectile* shoot(sf::Vector2f const& target);

    Projectile *getProjectile(sf::Vector2f const &target);

	Drawable& getDrawable();

private:
	
	Drawable m_drawable;

    float m_timeUntilShoot;
    bool m_isTimeToShoot;
	bool m_isShooting;

    float m_timeBetweenShoot;
    float m_targetingRange;
    float m_shootingRange;
};