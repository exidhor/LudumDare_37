//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_PATH_HPP
#define LUDUMDARE_PATH_HPP


#include <SFML/System.hpp>

class Path
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Path              ();
    explicit            Path              (sf::Vector2f fromPosition, sf::Vector2f toPosition);
    explicit            Path              (float fromX, float fromY, float toX, float toY);
    virtual             ~Path             ();
    sf::Vector2f        getFromPositions          ();
    sf::Vector2f        getToPositions            ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    sf::Vector2f m_fromPosition;
    sf::Vector2f m_toPosition;
};


#endif //LUDUMDARE_PATH_HPP