//
// Created by Kraghan on 10/12/2016.
//

#include <Player/Player.hpp>
#include <iostream>
#include <Utils/Singleton.hpp>
#include <Memory/Container.hpp>
#include "GameState/GameState.hpp"
#include "Music/MusicManager.hpp"

/* Explicit */ GameState::GameState()
: m_player(0)
, m_world()
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
        std::vector<DemoniacObject*> demoniacObjectsHit;
        m_world.getDemoniacObjectIn(sf::Vector2f(event.mouseButton.x,event.mouseButton.y),m_player.getClickRadius(),
                                      demoniacObjectsHit);

        for(auto objects : demoniacObjectsHit)
        {
            objects->hit(m_player.getDamage());
        }
        // Todo Animation
    }
    // Process money generation
    else if(event.type == sf::Event::KeyReleased)
    {
        m_player.increaseMoney(100);
    }
}

void GameState::update(double dt)
{
    // None
    m_world.prepare();
    for(auto object : m_demoniacObjects)
    {
        object.update(dt);
        m_world.addDemoniacObject(&object);
    }

}

void GameState::draw(sf::RenderWindow &window)
{
    m_world.draw(window);
}

bool GameState::onEnter()
{
    MusicManager::Instance()->FadeInOut(10.0, "MENU");

    // Init the player
    m_player = Player(150);
    m_world = World();
    m_world.addBackground(Container<sf::Texture>::Instance()->GetResource("BACKGROUND"));
    //m_world.addDecors();
    return true;
}

bool GameState::onExit()
{
    return true;
}

