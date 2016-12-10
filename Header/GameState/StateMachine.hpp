/*!
 * \brief   Header of the state machine
 * \file    StateMachine.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/10/2016
 */

#ifndef __STATE_MACHINE_HPP
#define __STATE_MACHINE_HPP

#include <vector>
#include "Utils/Singleton.hpp"
#include "Utils/Updatable.hpp"
#include "GameState/State.hpp"

class StateMachine : public Updatable, public Singleton <StateMachine>
{
public:

    /*!
     * \brief   Default constr
     */
    explicit StateMachine();

    /*!
     * \brief   Destructor
     */
    virtual ~StateMachine();

    /*!
     * \brief   Implements the update method
     * \param   dt The elapsed time
     */
    virtual void update(double dt);

    /*!
     * \brief Handle input
     * \param event The event
     * \param elapsed The elapsed time
     */
    void onPollEvent(sf::Event & event, double elapsed);

    /*!
     * \brief Draw the state
     * \param window The window to draw on
     */
    void render(sf::RenderWindow& window) ;

    /*!
     * \brief   Push a state at the top of the state machine
     * \param   pState The state to push
     */
    void pushState(State * pState);

    /*!
     * \brief   Remove the previous state before pushing another one
     * \param   pState The state to change with
     */
    void changeState(State * pState);

    /*!
     * \brief   Remove the state at the top of the state machine
     */
    void popState();

private:

    std::vector < State * > m_gameStates;
};

#endif // __STATE_MACHINE_HPP
