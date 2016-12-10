//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_GAMESTATE_HPP
#define LUDUMDARE_GAMESTATE_HPP


#include <Player/Player.hpp>
#include <Utils/Singleton.hpp>
#include <World.hpp>
#include "State.hpp"
#include "Spawner.hpp"

class GameState : public State, public Singleton < GameState >
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            GameState              ();
    virtual             ~GameState             ();

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

    virtual void update(double dt);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    Player                  m_player;
    World                   m_world;
    std::vector<DemoniacObject*> m_demoniacObjects;
	std::vector<Spawner> m_spawners;
};


#endif //LUDUMDARE_GAMESTATE_HPP
