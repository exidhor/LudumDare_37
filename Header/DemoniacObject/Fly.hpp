//
// Created by renaud on 10/12/16.
//

#ifndef LUDUMDARE_FLY_HPP
#define LUDUMDARE_FLY_HPP

#include "DemoniacObject/DemoniacObject.hpp"

#define FLY_LIFE 10
#define FLY_SPEED 10
#define FLY_DAMAGE 10

class Fly : public DemoniacObject
{
public:
    explicit Fly();
    explicit Fly(sf::Vector2f const& startPosition);

    void hit(int damage);
    Projectile shoot(Unit* target);
};

#endif //LUDUMDARE_FLY_HPP