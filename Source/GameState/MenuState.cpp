#include "GameState/MenuState.hpp"

/* explicit */ MenuState::MenuState()
{
    // None
}

void MenuState::init()
{

}

/* virtual */ MenuState::~MenuState()
{
    // None
}

/* virtual */ void MenuState::update(double dt)
{
    // TODO
}

bool MenuState::onEnter()
{
    // TODO
    return true;
}

bool MenuState::onExit()
{
    // TODO
    return true;
}

void MenuState::onPollEvent(sf::Event &event, double elapsed)
{
    // TODO
    (void)event;
    (void)elapsed;
}

void MenuState::draw(sf::RenderWindow& window)
{
    (void)window;
}
