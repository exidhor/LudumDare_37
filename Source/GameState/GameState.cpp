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
, m_spawners(sf::Vector2f())
{

}

/* Virtual */ GameState::~GameState()
{

}

void GameState::onPollEvent(sf::Event &event, double elapsed)
{
    m_view.processInput(event);

    if(getComponentId() == "EXIT_BUTTON")
    {
        StateMachine::Instance()->popState();
    }
    else if(getComponentId() == "OPT_BUTTON")
    {
        MusicManager::Instance()->PauseCurrent();
    }

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
}

void GameState::update(double dt)
{
	// None
	m_world.prepare();

    // 8f20
	// Update spawners
    m_spawners.updateTime(dt);

    if(m_spawners.isReadyToSpawn())
    {
        m_demoniacObjects.push_back(m_spawners.spawn());
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

    m_player.update(dt);

    m_view.setHitPoint(m_player.getLife());
    m_view.setMoney(m_player.get$Money$());
    m_view.setDifficulty(m_spawners.getDifficulty());
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
    sprite->setPosition(sf::Vector2f(580.0f,220.0f));
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("GEEK_1"));
    m_player.addSprite(sprite);
    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setPosition(sf::Vector2f(580.0f,220.0f));
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("GEEK_2"));
    m_player.addSprite(sprite);
    m_player.nextSprite();

	m_spawners = Spawner(m_player.getPosition());

	// 1280 / 768
	m_spawners.setPosition(sf::Vector2f(1280, 700));
    m_spawners.addPath(Path(1280.0f,700.0f,820.0f,680.0f));
    m_spawners.addPath(Path(820.0f,680.0f,780.0f,560.0f));
    m_spawners.addPath(Path(780.0f,560.0f,560.0f,560.0f));
    m_spawners.addPath(Path(560.0f,560.0f,520.0f,650.0f));
    m_spawners.addPath(Path(520.0f,650.0f,80.0f,700.0f));
    m_spawners.addPath(Path(80.0f,700.0f,80.0f,360.0f));
    m_spawners.addPath(Path(80.0f,360.0f,230.0f,360.0f));
    m_spawners.addPath(Path(230.0f,360.0f,250.0f,600.0f));
    m_spawners.addPath(Path(250.0f,600.0f,400.0f,550.0f));
    m_spawners.addPath(Path(400.0f,550.0f,430.0f,410.0f));
    m_spawners.addPath(Path(430.0f,410.0f,1190.0f,430.0f));
    m_spawners.addPath(Path(1190.0f,430.0f,1170.0f,200.0f));
    m_spawners.addPath(Path(1170.0f,200.0f,580.0f,190.0f));

    m_world.addBackground(Container<sf::Texture>::Instance()->GetResource("BACKGROUND"));
    //m_world.addDecors();

    return true;
}

bool GameState::onExit()
{
    return true;
}

