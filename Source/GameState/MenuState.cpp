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
    // Update view
    m_view.update(dt);
}

/* virtual */ void MenuState::onPollEvent(sf::Event &event, double elapsed)
{
    // Processing input
    m_view.processInput(event);
}

/* virtual */ void MenuState::draw(sf::RenderWindow& window)
{
    (void)window;
}

/* virtual */ bool MenuState::onEnter()
{
    // TODO
    return true;
}

/* virtual */ bool MenuState::onExit()
{
    // TODO
    return true;
}

