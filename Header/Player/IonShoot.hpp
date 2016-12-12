//
// Created by Kraghan on 12/12/2016.
//

#ifndef LUDUMDARE_IONSHOOT_HPP
#define LUDUMDARE_IONSHOOT_HPP

#include "Projectile.hpp"

#define SPEED_ION 1
#define DAMAGE_ION 35
#define TIME_BETWEEN_SWAP_ION 1000.0

class IonShoot : public Projectile
{
public:
    IonShoot();
    virtual ~IonShoot() {};

    sf::Vector2f move(sf::Vector2f const& position, float speed);
    void killDemoniacObject(const World world);
};


#endif //LUDUMDARE_IONSHOOT_HPP
