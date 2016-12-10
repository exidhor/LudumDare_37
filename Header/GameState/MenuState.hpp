/*!
 * \brief   Header of the class PauseState
 * \file    PauseState.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    18/10/2016
 */

#ifndef __PAUSE_STATE_HPP
#define __PAUSE_STATE_HPP

#include "Utils/Singleton.hpp"

/// Include previous and next states
#include "GameState/StateMachine.hpp"

class MenuState : public GameState, public Singleton < MenuState >
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
};

#endif // __PAUSE_STATE_HPP