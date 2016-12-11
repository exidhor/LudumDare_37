//
// Created by Kraghan on 10/12/2016.
//

#include <GameState/StateMachine.hpp>
#include "GameState/PauseState.hpp"

/* Explicit */ PauseState::PauseState()
: InputHandler(LD_DEBUG)
, m_view(LD_DEBUG, this)
{

}

/* Virtual */ PauseState::~PauseState()
{

}

bool PauseState::onExit()
{
    return true;
}

bool PauseState::onEnter() {
    return true;
}

void PauseState::draw(sf::RenderWindow &window)
{
    m_view.draw(&window);
}

void PauseState::onPollEvent(sf::Event &event, double elapsed)
{
    m_view.processInput(event);

    if(getComponentId() == "RESUME_BUTTON")
    {
        StateMachine::Instance()->popState();
    }

    if(event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == 36)
            StateMachine::Instance()->popState();

    }
}

void PauseState::update(double dt)
{
    m_view.update(dt);
}
