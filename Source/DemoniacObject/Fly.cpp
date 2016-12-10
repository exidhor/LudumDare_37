//
// Created by renaud on 10/12/16.
//

#include <Memory/Container.hpp>
#include "Memory/PoolAllocator.hpp"
#include "DemoniacObject/Fly.hpp"

Fly::Fly()
    : DemoniacObject(sf::Vector2f(), FLY_LIFE, FLY_SPEED, FLY_DAMAGE, FLY_ARMOR, FLY_SPRITESWAP)
{
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("FLY_1"));
    addSprite(sprite);

    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("FLY_2"));
    addSprite(sprite);

    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("FLY_3"));
    setDeathSprite(sprite);

    nextSprite();
}