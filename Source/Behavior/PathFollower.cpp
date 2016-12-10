//
// Created by Kraghan on 10/12/2016.
//

#include <MathHelper.hpp>
#include "Behavior/PathFollower.hpp"

/* Explicit */ PathFollower::PathFollower()
: m_initialPositions()
, m_currentPosition()
, m_currentPath()
{
    // None
}

/* Virtual */ PathFollower::~PathFollower()
{
    // None
}

/* Explicit */ PathFollower::PathFollower(sf::Vector2f initialPosition)
: m_initialPositions(initialPosition)
, m_currentPosition()
, m_currentPath()
{
    // None
}

void PathFollower::addPath(Path path)
{
    m_aPathes.push_back(path);
}

void PathFollower::addPath(sf::Vector2f from, sf::Vector2f to)
{
    m_aPathes.push_back(Path(from,to));
}

void PathFollower::addPath(float fromX, float fromY, float toX, float toY)
{
    m_aPathes.push_back(Path(fromX,fromY,toX,toY));
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
        if(position == path.getFromPositions())
        {
            if(path.getToPositions() == toPosition)
            {
                return true;
            }
            else
            {
                return hasPath(path.getToPositions(),toPosition);
            }
        }
    }
    return false;
}

bool PathFollower::hasPath(sf::Vector2f position, sf::Vector2f toPosition)
{
    if(position == toPosition)
    {
        return true;
    }

    for(auto path : m_aPathes)
    {
        if(position == path.getFromPositions())
        {
            if(path.getToPositions() == toPosition)
            {
                return true;
            }
            else
            {
                return hasPath(path.getToPositions(),toPosition);
            }
        }
    }
    return false;
}

void PathFollower::setCurrentPath(Path* currentPath)
{
    for(auto path : m_aPathes)
    {
        if(path.getToPositions() == currentPath->getToPositions()
                && path.getFromPositions() == currentPath->getFromPositions())
        {
            m_currentPath = currentPath;
            m_currentPosition = currentPath->getFromPositions();
        }
    }
}

void PathFollower::move(sf::Vector2f const &position, float speed)
{
    if(m_currentPath != nullptr)
    {
        sf::Vector2f deplacement = Movement::deplacement(position, m_currentPath->getToPositions(), speed);
        m_currentPosition += deplacement;

        if (m_currentPosition == m_currentPath->getToPositions()) {
            nextPath();
        }
    }
}

void PathFollower::nextPath()
{
    for(auto path : m_aPathes)
    {
        if(m_currentPath->getToPositions() == path.getFromPositions())
        {
            m_currentPath = &path;
        }
    }
    m_currentPath = nullptr;
}

sf::Vector2f const &PathFollower::getCurrentPosition() const {
    return m_currentPosition;
}