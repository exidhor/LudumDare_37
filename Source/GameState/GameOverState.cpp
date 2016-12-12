//
// Created by Kraghan on 10/12/2016.
//

#include "GameState/GameOverState.hpp"

/* Explicit */ GameOverState::GameOverState()
: InputHandler(LD_DEBUG)
, m_view(LD_DEBUG, this)
{

}

/* Virtual */ GameOverState::~GameOverState()
{

}

void GameOverState::update(double dt)
{
    // None
}

void GameOverState::onPollEvent(sf::Event &event, double elapsed)
{
    m_view.processInput(event);

    if(getComponentId() == "RESUME_BUTTON")
    {
        StateMachine::Instance()->popState();
        GameState::Instance()->reset();
    }

    if(getComponentId() == "BACK_TO_MAIN_MENU")
    {
        StateMachine::Instance()->popState();
        StateMachine::Instance()->popState();
    }
}

void GameOverState::draw(sf::RenderWindow &window)
{
    m_view.draw(&window);
}

bool GameOverState::onEnter() {
    return true;
}

bool GameOverState::onExit() {
    return true;
}
