//
// Created by Kraghan on 11/12/2016.
//

#ifndef LUDUMDARE_GAMEOVERVIEW_HPP
#define LUDUMDARE_GAMEOVERVIEW_HPP


#include <Interface/BasicInterface.hpp>
#include "Memory/Container.hpp"
#include "GameState/GameState.hpp"

class GameOverView : public BasicInterface
{
public :
    /// \brief Constructor
    /// \param debug Debug value
    /// \param inputHandler The controller
    explicit GameOverView(bool debug, InputHandler * inputHandler);

    /// \brief Destructor
    virtual ~GameOverView();

    /// \brief Update the menu
    /// \param elapsed The elapsed time
    virtual void update(double elapsed);

    /// \param e The event
    /// \param frameTime
    virtual void processInput(sf::Event & e);

    /// \param w The window
    virtual void draw(sf::RenderWindow * w);

private:
    NPanel m_background;
    NButton m_mainMenu;
    NButton m_replay;
};


#endif //LUDUMDARE_GAMEOVERVIEW_HPP
