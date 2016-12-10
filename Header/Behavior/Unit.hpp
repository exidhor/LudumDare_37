#ifndef __UNIT_HPP
#define __UNIT_HPP

#include <SFML/System.hpp>

class Unit
{
public:
    Unit(int life)
        : m_life(life)
    {
        // nothing
    }

    virtual bool hit(int damage) = 0;

    bool isDead() const
    {
        return m_life <= 0;
    }

    virtual sf::Vector2f getPosition() const = 0;

protected:
    int m_life;
};

#endif // __UNIT_HPP
