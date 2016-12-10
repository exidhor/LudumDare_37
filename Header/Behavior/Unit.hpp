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

    void setPosition(sf::Vector2f const& position)
    {
        m_position = position;
    }

    sf::Vector2f const& getPosition() const
    {
        return m_position;
    }

protected:
    int m_life;

private:
    sf::Vector2f m_position;
};

#endif // __UNIT_HPP
