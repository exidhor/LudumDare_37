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
    /// Return true if the pathfollower has a path to the point toPosition
    bool                hasPath                   (sf::Vector2f toPosition);
    /// Set the current path if is in the possible path
    void                setCurrentPath            (Path currentPath);

    virtual void        move                      (sf::Vector2f const& position, float speed);

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

    void                nextPath                  ();
};


#endif //LUDUMDARE_PATHFOLLOWER_HPP
