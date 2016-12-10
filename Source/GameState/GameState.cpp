//
// Created by Kraghan on 10/12/2016.
//

#include <Player/Player.hpp>
#include <iostream>
#include <Utils/Singleton.hpp>
#include <Memory/Container.hpp>
#include "GameState/GameState.hpp"
#include "Music/MusicManager.hpp"
#include <Memory/PoolAllocator.hpp>

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

	// Update spawners
	for(unsigned int i = 0; i < m_spawners.size(); i++)
	{
		m_spawners[i].updateTime(dt);

		if(m_spawners[i].isReadyToSpawn())
		{
            DemoniacObject * obj = m_spawners[i].spawn();
			m_demoniacObjects.push_back(obj);
		}
	}

    for(int i = 0; i < m_demoniacObjects.size();++i)
    {
        m_demoniacObjects[i]->update(dt);

		if(m_demoniacObjects[i]->toRemove())
		{
			m_demoniacObjects.erase(m_demoniacObjects.begin() + i);
			i--;
		}
		else
		{
			m_world.addDemoniacObject(m_demoniacObjects[i]);
		}
    }
	
	// todo : gestion de la difficulté
}

void GameState::draw(sf::RenderWindow & window)
{
    m_world.draw(window);
}

bool GameState::onEnter()
{
    MusicManager::Instance()->FadeInOut(10.0, "MENU");

    // Init the player
    m_player = Player(150);
    m_world = World();

    //m_world.addDecors(); // todo
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setPosition(sf::Vector2f(350.0f,10.0f));
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("FLY_1"));
    m_player.addSprite(sprite);
    m_player.nextSprite();

	m_spawners.push_back(Spawner(m_player.getPosition()));
	m_spawners.push_back(Spawner(m_player.getPosition()));
	m_spawners.push_back(Spawner(m_player.getPosition()));

	// 1280 / 768
	m_spawners[0].setPosition(sf::Vector2f(50, 700));
	m_spawners[1].setPosition(sf::Vector2f(360, 700));
	m_spawners[2].setPosition(sf::Vector2f(1200, 700));

    m_world.addBackground(Container<sf::Texture>::Instance()->GetResource("BACKGROUND"));
    //m_world.addDecors();

    return true;
}

bool GameState::onExit()
{
    return true;
}

