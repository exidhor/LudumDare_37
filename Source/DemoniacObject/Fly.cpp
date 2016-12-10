//
// Created by renaud on 10/12/16.
//

#include "DemoniacObject/Fly.hpp"

Fly::Fly(sf::Vector2f const &startPosition)
    : DemoniacObject(startPosition, FLY_LIFE, FLY_SPEED)
{
    // nothing
}

bool Fly::hit(int damage)
{
    m_life -= damage;
    return isDead();
}

Projectile Fly::shoot(Unit *target)
{
    target->hit(FLY_DAMAGE);
    return Projectile();
}