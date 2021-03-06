//
// Created by renaud on 10/12/16.
//

#ifndef LUDUMDARE_POISON_HPP
#define LUDUMDARE_POISON_HPP

#include <SFML/System.hpp>
#include "Player/Turret.hpp"

#define TIME_BETWEEN_SHOT 2
#define TARGETING_RANGE 40
#define SHOOTING_RANGE 40

class Poison : public Turret
{
public:
    Poison(sf::Vector2f const& position);

	virtual Projectile * getProjectile(sf::Vector2f const &target);
};

#endif //LUDUMDARE_POISON_HPP
