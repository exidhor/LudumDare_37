//
// Created by Kraghan on 12/12/2016.
//

#include "Player/Ion.hpp"
#include <Memory/Container.hpp>
#include <Player/IonShoot.hpp>

Ion::Ion(sf::Vector2f const &position)
        : Turret(TIME_BETWEEN_SHOT_ION, TARGETING_RANGE_ION, SHOOTING_RANGE_ION)
{
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("ION_IDLE"));
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("ION_SHOOT"));
    getDrawable().nextTexture();
    getDrawable().getSprite().setPosition(position);
}

Projectile* Ion::getProjectile(sf::Vector2f const &target)
{
    Projectile *projectile = new IonShoot();

    projectile->getDrawable().getSprite().setPosition(target);

    return projectile;
}
