/*!
 * \brief   Header of the game state
 * \file    StateMachine.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/10/2016
 */

#ifndef __GAME_STATE_HPP
#define __GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "Utils/Updatable.hpp"

class State : public Updatable
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit State();

    /*!
     * \brief   Destructor
     */
    virtual ~State();

    /*!
     * \brief Handle input
     * \param event The event
     * \param elapsed The elapsed time
     */
    virtual void onPollEvent(sf::Event& event, double elapsed) = 0;

    /*!
     * \brief Draw the state
     * \param window The window to draw on
     */
    virtual void draw(sf::RenderWindow & window) = 0;

    /*!
     * \brief   Function called when a state is pushed
     * \return  True if the state can be pushed
     */
    virtual bool onEnter() = 0;

    /*!
     * \brief   Function called when a state is popped
     * \return  True if the state can be popped
     */
    virtual bool onExit() = 0;
};

#endif // __GAME_STATE_HPP