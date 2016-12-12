//
// Created by Kraghan on 12/12/2016.
//

#ifndef LUDUMDARE_ION_HPP
#define LUDUMDARE_ION_HPP


#include "Turret.hpp"

#define TIME_BETWEEN_SHOT_ION 5
#define TARGETING_RANGE_ION 100
#define SHOOTING_RANGE_ION 80

class Ion : public Turret
{
public :
    Ion(sf::Vector2f const& position);

    Projectile * getProjectile(sf::Vector2f const &target);
};


#endif //LUDUMDARE_ION_HPP
