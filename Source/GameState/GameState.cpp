//
// Created by Kraghan on 10/12/2016.
//

#include <Player/Player.hpp>
#include <iostream>
#include "GameState/GameState.hpp"

/* Explicit */ GameState::GameState()
{

}

/* Virtual */ GameState::~GameState()
{

}

void GameState::onPollEvent(sf::Event &event, double elapsed)
{
    // Process player shoot
    if (event.type == sf::Event::MouseButtonPressed)
    {
        m_pworld->
    }
    // Process money generation
    else if(event.type == sf::Event::KeyReleased)
    {
        m_pplayer->increaseMoney(100);
    }
}

void GameState::update(double dt)
{
    // None
}

void GameState::draw(sf::RenderWindow &window)
{
    m_pworld->draw(window);
}

bool GameState::onEnter()
{
    // Init the player
    m_pplayer = new Player(150);

    return true;
}

bool GameState::onExit()
{
    delete m_pplayer;
    return true;
}

