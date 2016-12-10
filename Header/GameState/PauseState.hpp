//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_PAUSESTATE_HPP
#define LUDUMDARE_PAUSESTATE_HPP


#include <Utils/Singleton.hpp>
#include "State.hpp"

class PauseState : public State, public Singleton < PauseState >
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            PauseState              ();
    virtual             ~PauseState             ();

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

    /*!
     * \brief   Abstract method for updatable objects
     * \param
     */
    virtual void update(double dt);


    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //LUDUMDARE_PAUSESTATE_HPP
