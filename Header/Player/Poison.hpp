//
// Created by renaud on 10/12/16.
//

#ifndef LUDUMDARE_POISON_HPP
#define LUDUMDARE_POISON_HPP

#include <SFML/System.hpp>
#include "Player/Turret.hpp"

#define TIME_BETWEEN_SHOT 10

class Poison : public Turret
{
public:
    Poison(sf::Vector2f const& position);

    void update(double time);
    Projectile* shoot(sf::Vector2f const& target);
};

#endif //LUDUMDARE_POISON_HPP
