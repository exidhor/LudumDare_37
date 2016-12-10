//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_PATHFOLLOWER_HPP
#define LUDUMDARE_PATHFOLLOWER_HPP

#include <SFML/System.hpp>
#include "Path.hpp"
#include "Movable.hpp"
#include <vector>


class PathFollower : public Movable {
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            PathFollower              ();
    explicit            PathFollower              (sf::Vector2f initialPosition);
    virtual             ~PathFollower             ();
    void                addPath                   (Path path);
    void                addPath                   (sf::Vector2f from, sf::Vector2f to);
    void                addPath                   (float fromX, float fromY, float toX, float toY);
    bool                hasPath                   (sf::Vector2f toPosition);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    std::vector<Path>   m_aPathes;
    sf::Vector2f        m_initialPositions;
    sf::Vector2f        m_currentPosition;
    Path                m_currentPath;

    bool                hasPath                   (sf::Vector2f position, sf::Vector2f toPosition);
};


#endif //LUDUMDARE_PATHFOLLOWER_HPP
