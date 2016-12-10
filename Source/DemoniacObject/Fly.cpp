//
// Created by renaud on 10/12/16.
//

#include <Memory/Container.hpp>
#include "Memory/PoolAllocator.hpp"
#include "DemoniacObject/Fly.hpp"

Fly::Fly(sf::Vector2f const &startPosition)
    : DemoniacObject(startPosition, FLY_LIFE, FLY_SPEED, FLY_DAMAGE, FLY_ARMOR)
{
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("FLY_1"));
    addSprite(sprite);
    PoolAllocator<sf::Sprite>::Instance()->Deallocate(sprite);

    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("FLY_2"));
    addSprite(sprite);
    PoolAllocator<sf::Sprite>::Instance()->Deallocate(sprite);

    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("FLY_3"));
    setDeathSprite(sprite);
    PoolAllocator<sf::Sprite>::Instance()->Deallocate(sprite);

    nextSprite();
}