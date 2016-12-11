//
// Created by renaud on 11/12/16.
//

#include <Memory/PoolAllocator.hpp>
#include <Memory/Container.hpp>
#include "Player/Pschit.hpp"

Pschit::Pschit()
    : Projectile(SPEED, DAMAGE, TIME_BETWEEN_SWAP)
{
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("PSCHIT_1"));
    addSprite(sprite);

    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("PSCHIT_2"));
    addSprite(sprite);

    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("PSCHIT_3"));
    addSprite(sprite);

    nextSprite();
}

sf::Vector2f Pschit::move(sf::Vector2f const &position, float speed)
{
    return position;
}