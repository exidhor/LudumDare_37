//
// Created by renaud on 10/12/16.
//

#include "DemoniacObject/Fly.hpp"
#include "Projectile.hpp"

Fly::Fly(sf::Vector2f const &startPosition)
    : DemoniacObject(startPosition, FLY_LIFE, FLY_SPEED, FLY_DAMAGE, FLY_ARMOR)
{
    // nothing
}