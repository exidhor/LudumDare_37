#include "GameState/StateMachine.hpp"

/* explicit */ StateMachine::StateMachine()
{
    // None
}

/* virtual */ StateMachine::~StateMachine()
{
    // None
}

/* virtual */ void StateMachine::update(double dt)
{
    // Updating only the last state
    if(!m_gameStates.empty()) m_gameStates.back()->update(dt);
}

void StateMachine::onPollEvent(sf::Event & event, double elapsed)
{
    // Processing event
    if(!m_gameStates.empty()) m_gameStates.back()->onPollEvent(event, elapsed);
}

void StateMachine::render(sf::RenderWindow &window)
{
    // Draw the current state
    if(!m_gameStates.empty()) m_gameStates.back()->draw(window);
}

void StateMachine::pushState(State * pState)
{
    // Pushing the state at the top of
    // State machine, calling onEnter()
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void StateMachine::changeChange(State * pState)
{
    popState();
    pushState(pState);
}

void StateMachine::popState()
{
    // If the state machine isn't empty
    if(!m_gameStates.empty())
    {
        // If onExit succeed
        if(m_gameStates.back()->onExit())
        {
            // Removing the last state
            m_gameStates.pop_back();
        }
    }
}
