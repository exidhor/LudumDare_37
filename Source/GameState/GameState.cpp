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

    }
    // Process money generation
    else if(event.type == sf::Event::KeyReleased)
    {
        m_pplayer->increaseMoney(100);
        std::cout<< m_pplayer->get$Money$() <<std::endl;
    }
}

void GameState::draw(sf::RenderWindow &window)
{

}

bool GameState::onEnter()
{
    // Init the player
    m_pplayer = new Player(150);

    return false;
}

bool GameState::onExit()
{
    return false;
}

