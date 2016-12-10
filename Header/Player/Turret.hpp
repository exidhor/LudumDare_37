#pragma once

#include <SFML/System.hpp>

#include "World.hpp"
#include "Graphics/Drawable.hpp"
#include "Player/Projectile.hpp"

class Turret : public Drawable
{
public :
	Turret(float m_timeBetWeenShoot, float targetingRange, float shootingRange);

    void update(double time, const World world);
    Projectile* shoot(sf::Vector2f const& target);

    virtual Projectile *getProjetile(sf::Vector2f const &target) = 0;

    float getTargetingRange() const;
    float getShootingRange() const;

protected:
    float m_timeUntilShoot;
    bool m_isTimeToShoot;
	bool m_isShooting;

private:
    float m_timeBetweenShoot;
    float m_targetingRange;
    float m_shootingRange;
};