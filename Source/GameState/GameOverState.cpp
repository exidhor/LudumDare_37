//
// Created by Kraghan on 10/12/2016.
//

#include "GameState/GameOverState.hpp"

/* Explicit */ GameOverState::GameOverState()
{

}

/* Virtual */ GameOverState::~GameOverState()
{

}

void GameOverState::update(double dt)
{
    // None
}

void GameOverState::onPollEvent(sf::Event &event, double elapsed) {

}

void GameOverState::draw(sf::RenderWindow &window) {

}

bool GameOverState::onEnter() {
    return false;
}

bool GameOverState::onExit() {
    return false;
}
