//
// Created by renaud on 11/12/16.
//

#ifndef LUDUMDARE_PSCHIT_HPP
#define LUDUMDARE_PSCHIT_HPP

#include "Player/Projectile.hpp"

#define SPEED 0
#define DAMAGE 10
#define TIME_BETWEEN_SWAP 0.1

class Pschit : public Projectile
{
public:
    Pschit();

    sf::Vector2f move(sf::Vector2f const& position, float speed);
};

#endif //LUDUMDARE_PSCHIT_HPP
