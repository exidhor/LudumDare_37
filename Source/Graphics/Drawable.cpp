//
// Created by Kraghan on 10/12/2016.
//

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
    // None
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
}

void Drawable::setDeathSprite(sf::Sprite* sprite)
{
    m_deathSprite = sprite;
}

void Drawable::activeDeathSprite()
{
    currentSprite = m_deathSprite;
}