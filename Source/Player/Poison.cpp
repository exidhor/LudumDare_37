//
// Created by renaud on 10/12/16.
//

#include <Memory/PoolAllocator.hpp>
#include <Memory/Container.hpp>
#include "Player/Poison.hpp"

Poison::Poison(sf::Vector2f const &position)
    : Turret(TIME_BETWEEN_SHOT, TARGETING_RANGE, SHOOTING_RANGE)
{
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("TURRET_IDLE"));
    sprite->setPosition(position);
    addSprite(sprite);

    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("TURRET_SHOOT"));
    sprite->setPosition(position);
    addSprite(sprite);

    nextSprite();
}

Projectile* Turret::getProjetile(sf::Vector2f const &target)
{
    Projectile *projectile = nullptr;

    //TODO - create Projectile

    return projectile;
}