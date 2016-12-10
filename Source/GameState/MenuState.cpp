#include <SFML/Audio.hpp>
#include <Music/MusicManager.hpp>

#include "GameState/GameState.hpp"
#include "GameState/MenuState.hpp"

/* explicit */ MenuState::MenuState()
: InputHandler(LD_DEBUG)
, m_view(LD_DEBUG, this)
{
    // None
}

/* virtual */ void MenuState::init()
{
    // None
}

/* virtual */ MenuState::~MenuState()
{
    // None
}

/* virtual */ void MenuState::update(double dt)
{
    m_view.update(dt);
}

/* virtual */ void MenuState::onPollEvent(sf::Event &event, double elapsed)
{
    // Processing input
    m_view.processInput(event);

    // Checking input
    if(getComponentId() == "START_BUTTON")
    {
        StateMachine::Instance()->pushState(GameState::Instance());
    }
    else if(getComponentId() == "EXIT_BUTTON")
    {
        StateMachine::Instance()->exit();
    }
    else if(getComponentId() == "SOUND_BUTTON")
    {
       MusicManager::Instance()->PauseCurrent();
    }
}

/* virtual */ void MenuState::draw(sf::RenderWindow& window)
{
    m_view.draw(&window);
}

/* virtual */ bool MenuState::onEnter()
{
    MusicManager::Instance()->FadeInOut(4.0, "MENU");
    return true;
}

/* virtual */ bool MenuState::onExit()
{
    // TODO
    return true;
}