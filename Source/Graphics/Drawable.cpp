//
// Created by Kraghan on 10/12/2016.
//

#include "Drawable.hpp"

/* Explicit */ Drawable::Drawable()
{

}

/* Virtual */ Drawable::~Drawable()
{

}

void Drawable::addSprite(sf::Sprite* sprite)
{
    m_pSprites.push_back(sprite);
}

void Drawable::nextSprite()
{

}

