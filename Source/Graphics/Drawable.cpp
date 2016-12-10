//
// Created by Kraghan on 10/12/2016.
//

#include "Memory/PoolAllocator.hpp"
#include "Graphics/Drawable.hpp"

/* Explicit */ Drawable::Drawable()
: currentSprite(nullptr)
, m_spriteId(0)
, m_deathSprite(nullptr)
{
    // None
}

/* Virtual */ Drawable::~Drawable()
{
    for (sf::Sprite *sprite : m_pSprites)
    {
        PoolAllocator<sf::Sprite>::Instance()->Deallocate(sprite);
    }
    PoolAllocator<sf::Sprite>::Instance()->Deallocate(m_deathSprite);
}

void Drawable::addSprite(sf::Sprite* sprite)
{
    m_pSprites.push_back(sprite);
}

void Drawable::nextSprite()
{
    ++m_spriteId;
    if(m_spriteId >= m_pSprites.size())
        m_spriteId = 0;
    currentSprite = m_pSprites[m_spriteId];
	currentSprite->setOrigin(currentSprite->getGlobalBounds().width / 2,
							 currentSprite->getGlobalBounds().height / 2);
}

void Drawable::setDeathSprite(sf::Sprite* sprite)
{
    m_deathSprite = sprite;
    m_deathSprite->setOrigin(m_deathSprite->getGlobalBounds().width / 2,
                             m_deathSprite->getGlobalBounds().height / 2);
}

void Drawable::activeDeathSprite()
{
    sf::Vector2f const& position = currentSprite->getPosition();
    m_deathSprite->setPosition(position);
    currentSprite = m_deathSprite;
}