#ifndef __UNIT_HPP
#define __UNIT_HPP

#include <SFML/System.hpp>

class Unit
{
public:
    explicit Unit()
        : m_position(nullptr),
          m_life(0)
    {
        // nothing
    }

    explicit Unit(sf::Vector2f const& startPosition, int life)
        : m_position(startPosition),
          m_life(life)
    {
        // nothing
    }

    virtual void hit(int damage) = 0;

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
