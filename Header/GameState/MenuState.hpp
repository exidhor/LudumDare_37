/*!
 * \brief   Header of the class PauseState
 * \file    PauseState.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    18/10/2016
 */

#ifndef __PAUSE_STATE_HPP
#define __PAUSE_STATE_HPP

#include "Menu/MenuView.hpp"
#include "Utils/Singleton.hpp"
#include "Interface/BasicInterface.hpp"

/// Include previous and next states
#include "GameState/StateMachine.hpp"

class MenuState : public GameState, public InputHandler, public Singleton < MenuState >
{
public:

    /*!
     * \brief    Constructor
     */
    explicit MenuState();

    /*!
     * \brief     Init method
     */
    void init();

    /*!
     * \brief   Destructor
     */
    virtual ~MenuState();

    /*!
     * \brief   Function called when a state is pushed
     * \return  True if the state can be pushed
     */
    virtual bool onEnter();

    /*!
     * \brief   Function called when a state is popped
     * \return  True if the state can be popped
     */
    virtual bool onExit();

    /*!
     * \brief   Implementing update methods
     * \param   The elapsed time since last update
     */
    virtual void update(double dt);

    /*!
     * \brief Handle input
     * \param event The event
     * \param elapsed The elapsed time
     */
    virtual void onPollEvent(sf::Event & event, double elapsed);

    /*!
     * \brief Draw the state
     * \param window The window to draw on
     */
    virtual void draw(sf::RenderWindow & window);

private:

    MenuView m_view; ///< The view of the menu
};

#endif // __PAUSE_STATE_HPP