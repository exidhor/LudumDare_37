//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_GAMESTATE_HPP
#define LUDUMDARE_GAMESTATE_HPP


#include <Player/Player.hpp>
#include <Utils/Singleton.hpp>
#include <World.hpp>
#include <Interface/InputHandler.hpp>
#include <View/GameView.hpp>
#include <Overlay.hpp>
#include "State.hpp"
#include "Spawner.hpp"
#include "Player/ClickEffect.hpp"
#include "Player/Poison.hpp"

#define NUMBER_SPRITE 400

class GameState : public State, public InputHandler, public Singleton < GameState >
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

    void         reset();

    virtual void update(double dt);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    GameView                m_view;
    Player                  m_player;
    World                   m_world;
    std::vector<DemoniacObject*> m_demoniacObjects;
    std::vector<Turret>    m_turrets;
    std::vector<Projectile*>    m_projectiles;
	Spawner                 m_spawners;
    bool                    m_gamePhase;
    int                     m_nextBonusPhaseIn;
    bool                    m_bonusPhase;
    bool                    m_shopPhase;
    double                  m_nextRoundIn;
    Drawable                m_screen;
    double                  m_screenElapsed;
    Overlay                 m_overlay;

	ClickEffect             m_clickEffect;

    const int               m_MONEY_PER_ROUND = 250;
    const double            m_NEXT_ROUND_IN = 10.0;
    const double            m_TIME_SCREEN_SWAP = 0.2;
    const int               m_NEXT_BONUS_PHASE_MAX = 7;
    const int               m_NEXT_BONUS_PHASE_MIN = 5;
};


#endif //LUDUMDARE_GAMESTATE_HPP
