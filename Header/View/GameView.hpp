#ifndef __GAME_VIEW_HPP
#define __GAME_VIEW_HPP

#include "Interface/BasicInterface.hpp"

class GameView : public BasicInterface
{
    /// \brief Constructor
    /// \param debug Debug value
    /// \param inputHandler The controller
    explicit GameView(bool debug, InputHandler * inputHandler);

    /// \brief Destructor
    virtual ~GameView();

    /// \brief Update the menu
    /// \param elapsed The elapsed time
    virtual void update(double elapsed);

    /// \param e The event
    /// \param frameTime
    virtual void processInput(sf::Event & e);

    /// \param w The window
    virtual void draw(sf::RenderWindow * w);
};

#endif // __GAME_VIEW_HPP