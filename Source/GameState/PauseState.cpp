//
// Created by Kraghan on 10/12/2016.
//

#include "GameState/PauseState.hpp"

/* Explicit */ PauseState::PauseState()
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

}

void PauseState::onPollEvent(sf::Event &event, double elapsed)
{

}

void PauseState::update(double dt)
{

}
