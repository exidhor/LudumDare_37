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
#include <GameState/StateMachine.hpp>
#include <GameState/PauseState.hpp>

/* Explicit */ GameState::GameState()
: InputHandler(LD_DEBUG)
, m_view(LD_DEBUG, this)
, m_player(0)
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

        for(unsigned i = 0; i < demoniacObjectsHit.size(); ++i)
        {
            demoniacObjectsHit[i]->hit(m_player.getDamage());
            std::cout<< demoniacObjectsHit[i]->getLife() << std::endl;
        }
        // Todo Animation
    }
    // Process money generation
    else if(event.type == sf::Event::KeyReleased)
    {
        if(event.key.code == 36)
            StateMachine::Instance()->pushState(PauseState::Instance());
        else
            m_player.increaseMoney(100);
    }

    m_view.processInput(event);
}

void GameState::update(double dt)
{
	// None
	m_world.prepare();

    // 8f20
	// Update spawners
	for(unsigned int i = 0; i < m_spawners.size(); ++i)
	{
		m_spawners[i].updateTime(dt);

		if(m_spawners[i].isReadyToSpawn())
		{
			m_demoniacObjects.push_back(m_spawners[i].spawn());
		}
	}

    for(int i = 0; i < (int)m_demoniacObjects.size();++i)
    {
        bool justDie = m_demoniacObjects[i]->isDead();
        m_demoniacObjects[i]->update(dt);
        if(!justDie && m_demoniacObjects[i]->isDead())
            m_player.hit(m_demoniacObjects[i]->getDamage());

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

    m_view.update(dt);
	
	// todo : gestion de la difficulté
}

void GameState::draw(sf::RenderWindow & window)
{
    m_world.addDrawable(&m_player);
    m_world.draw(window);
    m_view.draw(&window);
}

bool GameState::onEnter()
{
    MusicManager::Instance()->FadeInOut(10.0, "MENU");

    // Init the player
    m_player = Player(150);
    m_world = World();

    //m_world.addDecors(); // todo
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setPosition(sf::Vector2f(617.5f,175.0f));
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("FLY_1"));
    m_player.addSprite(sprite);
    m_player.nextSprite();

	m_spawners.push_back(Spawner(m_player.getPosition()));

	// 1280 / 768
	m_spawners[0].setPosition(sf::Vector2f(1280, 755));
    m_spawners[0].addPath(Path(1280.0f,755.0f,870.0f,755.0f));
    //m_spawners[0].addPath(Path(900.0f,675.0f,890.0f,670.0f));
    //m_spawners[0].addPath(Path(890.0f,670.0f,880.0f,665.0f));
    //m_spawners[0].addPath(Path(880.0f,665.0f,870.0f,660.0f));
    //m_spawners[0].addPath(Path(20.0f,400.0f,1000.0f,200.0f));
    //m_spawners[0].addPath(Path(1000.0f,200.0f,350.0f,10.0f));

    m_world.addBackground(Container<sf::Texture>::Instance()->GetResource("BACKGROUND"));
    //m_world.addDecors();

    return true;
}

bool GameState::onExit()
{
    return true;
}

