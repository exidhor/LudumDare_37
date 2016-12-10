//
// Created by Kraghan on 10/12/2016.
//

#include "Behavior/Path.hpp"

/* Explicit */ Path::Path()
: m_fromPosition()
, m_toPosition()
{
    // None
}

/* Virtual */ Path::~Path()
{
    // None
}

Path::Path(sf::Vector2f fromPosition, sf::Vector2f toPosition)
: m_fromPosition(fromPosition)
, m_toPosition(toPosition)
{
    // None
}

Path::Path(float fromX, float fromY, float toX, float toY)
: m_fromPosition(fromX,fromY)
, m_toPosition(toX,toY)
{
    // None
}


sf::Vector2f Path::getFromPositions()
{
    return m_fromPosition;
}

sf::Vector2f Path::getToPositions()
{
    return m_;
}