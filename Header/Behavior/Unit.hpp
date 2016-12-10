#ifndef __UNIT_HPP
#define __UNIT_HPP

#include <SFML/System.hpp>

class Unit
{
public:
    Unit(sf::Vector2f const& startPosition, int life)
        : m_position(startPosition),
          m_life(life)
    {
        // nothing
    }

    virtual void targeted(int damage) = 0;
    virtual sf::Vector2f getPosition() const = 0;

protected:
    int m_life;
    sf::Vector2f m_position;
};

#endif // __UNIT_HPP
