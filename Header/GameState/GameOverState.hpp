//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_GAMEOVERSTATE_HPP
#define LUDUMDARE_GAMEOVERSTATE_HPP

#include <Utils/Singleton.hpp>
#include <View/GameOverView.hpp>
#include "GameState/StateMachine.hpp"
#include "GameState/GameState.hpp"
#include "State.hpp"

class GameOverState : public State, public Singleton < GameOverState >, public InputHandler
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            GameOverState              ();
    virtual             ~GameOverState             ();

    void                update                     (double dt);

    /*!
     * \brief Handle input
     * \param event The event
     * \param elapsed The elapsed time
     */
    virtual void onPollEvent(sf::Event& event, double elapsed);

    /*!
     * \brief Draw the state
     * \param window The window to draw on
     */
    virtual void draw(sf::RenderWindow & window);

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

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    GameOverView m_view;
};


#endif //LUDUMDARE_GAMEOVERSTATE_HPP
