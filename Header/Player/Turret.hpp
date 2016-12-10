#pragma once

#include <SFML/System.hpp>

#include "Graphics/Drawable.hpp"
#include "Player/Projectile.hpp"

class Turret : public Drawable
{
public :
	Turret(double targetingRange, double shootingRange);

    virtual void update(double time) = 0;
    virtual Projectile* shoot(sf::Vector2f const& target) = 0;

    double getTargetingRange() const;
    double getShootingRange() const;

protected:
	double m_timeUntilShoot;
    bool m_isTimeToShoot;
	bool m_isShooting;

private:
    double m_targetingRange;
    double m_shootingRange;
};