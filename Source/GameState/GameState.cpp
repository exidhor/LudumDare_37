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
, m_gamePhase(true)
, m_nextRoundIn(0.0)
, m_bonusPhase(false)
, m_overlayPhase(false)
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
        m_world.getDemoniacObjectIn(sf::Vector2f(event.mouseButton.x,event.mouseButton.y),
                                    m_player.getClickRadius(), demoniacObjectsHit);

        for(unsigned i = 0; i < demoniacObjectsHit.size(); ++i)
        {
            demoniacObjectsHit[i]->hit(m_player.getDamage());
        }

        // Todo Animation
    }
    // Process money generation
    else if(event.type == sf::Event::KeyReleased)
    {
        if(event.key.code == 36)
            StateMachine::Instance()->pushState(PauseState::Instance());
        else
        {
            if(m_gamePhase)
            {
                if (m_bonusPhase)
                    m_player.increaseMoney(100);
                else if (m_overlayPhase)
                {
                    if (event.key.code == m_overlayKey)
                    {
                        m_overlayPhase = false;
                        m_player.increaseMoney(m_spawners.getDifficulty() * 100);
                    }
                }
            }
        }
    }
}

void GameState::update(double dt)
{
	// None
	m_world.prepare();

    if(m_gamePhase)
    {
        // Round phase

        m_view.hideNextRoundIn();

        // Update spawners
        m_spawners.updateTime(dt);

        if (m_spawners.isReadyToSpawn() && !m_spawners.outOfToken())
        {
            m_demoniacObjects.push_back(m_spawners.spawn());
        }

        for (int i = 0; i < (int) m_demoniacObjects.size(); ++i)
        {
            bool justDie = m_demoniacObjects[i]->isDead();
            m_demoniacObjects[i]->update(dt);
            if (!justDie && m_demoniacObjects[i]->isDead())
                m_player.hit(m_demoniacObjects[i]->getDamage());

            if (m_demoniacObjects[i]->toRemove())
            {
                m_demoniacObjects.erase(m_demoniacObjects.begin() + i);
                i--;
            }
            else
            {
                m_world.addDemoniacObject(m_demoniacObjects[i]);
            }
        }

        // End of round
        if(m_spawners.outOfToken() && m_demoniacObjects.size() == 0)
        {
            if(m_overlayPhase)
            {
                m_overlayPhase = false;
                m_nextOverlayPhaseIn = rand() % 3 + 1;
            }
            else
            {
                --m_nextOverlayPhaseIn;
                if(m_nextOverlayPhaseIn == 0)
                    m_overlayPhase = true;
            }

            if(m_bonusPhase)
            {
                m_bonusPhase = false;
                m_nextBonusPhaseIn = rand() % 3 + 5;
            }
            else
            {
                --m_nextBonusPhaseIn;
                if(m_nextBonusPhaseIn == 0)
                    m_bonusPhase = true;
            }

            m_player.increaseMoney(250*(m_spawners.getDifficulty()+1));
            m_spawners.increaseDifficulty();
            // Shop phase duration
            m_nextRoundIn = 10.0;
            m_gamePhase = false;
        }
    }
    else
    {
        // Shop phase
        m_nextRoundIn -= dt;
        m_view.setNextRoundIn(m_nextRoundIn > 0.0 ? (int)m_nextRoundIn : 0.0);
        if(m_nextRoundIn <= 0)
        {
            m_gamePhase = true;
            m_spawners.giveToken();
        }
    }
    m_player.update(dt);
    m_screenElapsed += dt;
    if(m_screenElapsed >= 0.20)
    {
        m_screen.nextSprite();
        m_screenElapsed = 0.0;
    }

    m_view.setHitPoint(m_player.getLife());
    m_view.setMoney(m_player.get$Money$());
    m_view.setDifficulty(m_spawners.getDifficulty());
    m_view.update(dt);
}

void GameState::draw(sf::RenderWindow & window)
{
    m_world.addDrawable(&m_player);
    m_world.addDrawable(&m_screen);
    m_world.draw(window);
    m_view.draw(&window);
    if(m_bonusPhase)
    {
        m_view.showBonusPhase();
    }
    else if(m_overlayPhase)
    {
        // Todo display overlay
    }

    if(!m_bonusPhase)
        m_view.hideBonusPhase();
}

bool GameState::onEnter()
{
    MusicManager::Instance()->FadeInOut(10.0, "MENU");

    // Init the player
    m_player = Player(150);
    m_world = World();

    //m_world.addDecors(); // todo
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setPosition(sf::Vector2f(617.0f,237.0f));
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("GEEK_1"));
    m_player.addSprite(sprite);
    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setPosition(sf::Vector2f(617.0f,237.0f));
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("GEEK_2"));
    m_player.addSprite(sprite);
    m_player.nextSprite();

    // Micro animation for screen
    sf::Sprite* spriteScreen = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    spriteScreen->setPosition(sf::Vector2f(603.0f,139.0f));
    spriteScreen->setTexture(*Container<sf::Texture>::Instance()->GetResource("SCREEN_1"));
    m_screen.addSprite(spriteScreen);
    spriteScreen = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    spriteScreen->setPosition(sf::Vector2f(603.0f,139.0f));
    spriteScreen->setTexture(*Container<sf::Texture>::Instance()->GetResource("SCREEN_2"));
    m_screen.addSprite(spriteScreen);
    m_screen.nextSprite();

	m_spawners = Spawner(m_player.getPosition());
    m_spawners.giveToken();

	// 1280 / 768
	m_spawners.setPosition(sf::Vector2f(1280, 700));
    m_spawners.addPath(Path(1280.0f,700.0f,835.0f,675.0f));
    m_spawners.addPath(Path(835.0f,675.0f,785.0f,550.0f));
    m_spawners.addPath(Path(785.0f,550.0f,560.0f,555.0f));
    m_spawners.addPath(Path(560.0f,555.0f,480.0f,720.0f));
    m_spawners.addPath(Path(480.0f,720.0f,190.0f,660.0f));
    m_spawners.addPath(Path(190.0f,660.0f,135.0f,350.0f));
    m_spawners.addPath(Path(135.0f,350.0f,270.0f,365.0f));
    m_spawners.addPath(Path(270.0f,365.0f,365.0f,540.0f));
    m_spawners.addPath(Path(365.0f,540.0f,605.0f,355.0f));
    m_spawners.addPath(Path(605.0f,355.0f,870.0f,450.0f));
    m_spawners.addPath(Path(870.0f,450.0f,1200.0f,360.0f));
    m_spawners.addPath(Path(1200.0f,360.0f,1115.0f,235.0f));
    m_spawners.addPath(Path(1115.0f,235.0f,620.0f,200.0f));

    m_world.addBackground(Container<sf::Texture>::Instance()->GetResource("BACKGROUND"));
    //m_world.addDecors();

    m_nextBonusPhaseIn = rand() % 3 + 5;
    m_nextOverlayPhaseIn = rand() % 3 + 1;

    return true;
}

bool GameState::onExit()
{
    return true;
}

