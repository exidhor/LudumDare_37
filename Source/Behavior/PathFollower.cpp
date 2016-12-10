//
// Created by Kraghan on 10/12/2016.
//

#include "Behavior/PathFollower.hpp"

/* Explicit */ PathFollower::PathFollower()
{
    
}

/* Virtual */ PathFollower::~PathFollower()
{
    
}

PathFollower::PathFollower(sf::Vector2f initialPosition)
{

}

void PathFollower::addPath(Path path)
{

}

void PathFollower::addPath(sf::Vector2f from, sf::Vector2f to)
{

}

void PathFollower::addPath(float fromX, float fromY, float toX, float toY)
{

}

bool PathFollower::hasPath(sf::Vector2f toPosition)
{
    sf::Vector2f position = m_initialPositions;
    if(position == toPosition)
    {
        return true;
    }

    for(auto path : m_aPathes)
    {
        if(path.getToPositions() == toPosition)
        {

        }
    }
}