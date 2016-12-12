//
// Created by Kraghan on 10/12/2016.
//

#include <Player/Player.hpp>
#include <iostream>
#include <Utils/Singleton.hpp>
#include <Memory/Container.hpp>
#include "GameState/GameState.hpp"
#include "Music/MusicManager.hpp"
#include <GameState/StateMachine.hpp>
#include <GameState/PauseState.hpp>
#include <Player/Ion.hpp>
#include "Player/Pschit.hpp"

/* Explicit */
GameState::GameState()
	: InputHandler(LD_DEBUG)
	  , m_view(LD_DEBUG, this)
	  , m_player(0)
	  , m_world()
	  , m_spawners(sf::Vector2f())
	  , m_gamePhase(true)
	  , m_bonusPhase(false)
	  , m_shopPhase(false)
      , m_window(nullptr)
	  , m_turretIsSelected(false)
	  , m_turretSelected(nullptr)
	  , m_nextRoundIn(0.0)
{
}

/* Virtual */
GameState::~GameState()
{
}

void GameState::onPollEvent(sf::Event& event, double elapsed)
{
	m_view.processInput(event);

	// Process turret positioning
	if (m_turretIsSelected)
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			// Making course
			m_player.setMoney(m_player.get$Money$() - m_priceOfTheCurrentTurret);

			// verify if there was a turret their
			for (int i = 0; i < (int)m_turrets.size(); i++)
			{
				if (m_turrets[i]->getDrawable().getSprite().getPosition() == m_turretSelected->getDrawable().getSprite().getPosition())
				{
					// destroy the turret if it was at the same position
					//delete m_turrets[i];
					//m_turrets.erase(m_turrets.begin() + i);
					break;
				}
			}
			m_turrets.push_back(m_turretSelected);
			m_turretSelected->getDrawable().getSprite().setColor(sf::Color(255, 255, 255, 255));
			m_turretSelected = nullptr;
			m_turretIsSelected = false;
		}
	}

	if (getComponentId() == "SOUND_BUTTON_ON")
	{
		MusicManager::Instance()->PauseCurrent();
		m_view.EnableSound();
	}
	else if (getComponentId() == "SOUND_BUTTON_OFF")
	{
		MusicManager::Instance()->PauseCurrent();
		m_view.DisableSound();
	}
	else if (getComponentId() == "SHOP_EXIT")
	{
		m_view.hideShop();
	}
	else if (getComponentId() == "SHOP_ENTER")
	{
		m_view.showShop();
	}
	else if (getComponentId().size() == 5)
	{
		std::string check = getComponentId().substr(0, 3);
		if (check == "BUY")
		{
			char itemID = getComponentId()[4] - '0';
			ShopItem* item = m_view.getShopItem((unsigned)itemID);
			// Checking money
			if (m_player.get$Money$() >= item->getPrice())
			{
				m_turretIsSelected = true;
				if(itemID == '0')
					m_turretSelected = new Poison(sf::Vector2f());
				else
					m_turretSelected = new Ion(sf::Vector2f());
				m_priceOfTheCurrentTurret = item->getPrice();
				// Closing store
				m_view.hideShop();
			}
		}
	}

	// Process player shoot
	if (event.type == sf::Event::MouseButtonPressed)
	{
		std::vector<DemoniacObject*> demoniacObjectsHit;
		m_world.getDemoniacObjectIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y),
		                            m_player.getClickRadius(), demoniacObjectsHit);

		for (unsigned i = 0; i < demoniacObjectsHit.size(); ++i)
		{
			demoniacObjectsHit[i]->hit(m_player.getDamage());
		}

		// click effect
		if (m_gamePhase && !m_overlay.isOverlayPhase())
		{
			// todo : add more verif ? 
			m_clickEffect.addEffect(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
		}
	}
	// Process money generation
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == 36)
			StateMachine::Instance()->pushState(PauseState::Instance());
		else
		{
			if (m_gamePhase)
			{

				if (m_overlay.isOverlayPhase())
				{
					if (event.key.code == m_overlay.getKeycode())
					{
						m_overlay.endPhase();
						m_player.increaseMoney(m_spawners.getDifficulty() * Overlay::m_OVERLAY_REWARD);
					}
				}
				else if (m_bonusPhase)
					m_player.increaseMoney(100);
			}
		}
	}
}

void GameState::update(double dt)
{
	// None
	m_world.prepare();

	m_clickEffect.update(dt);

	if (m_gamePhase)
	{
		// Shop phase
		if (m_shopPhase)
		{
			m_shopPhase = false;
			m_view.hideShopButton();
			m_view.hideShop();
		}

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
				delete m_demoniacObjects[i];
				m_demoniacObjects.erase(m_demoniacObjects.begin() + i);
				i--;
			}
			else
			{
				m_world.addDemoniacObject(m_demoniacObjects[i]);
			}
		}

		// Turrets
		for (int i = 0; i < (int) m_turrets.size(); i++)
		{
			m_turrets[i]->update(dt, m_world);

			Projectile* projectile = m_turrets[i]->shoot();

			if (projectile != nullptr)
			{
				m_projectiles.push_back(projectile);
			}
		}

		for (int i = 0; i < (int) m_projectiles.size(); i++)
		{
			m_projectiles[i]->update(dt);
			m_projectiles[i]->killDemoniacObject(m_world);
			if (m_projectiles[i]->toRemove())
			{
				delete m_projectiles[i];
				m_projectiles.erase(m_projectiles.begin() + i);
				i--;
			}
		}

		// End of round
		if (m_spawners.outOfToken() && m_demoniacObjects.size() == 0)
		{
			if (!m_overlay.isOverlayPhase())
			{
				m_overlay.prepareNextOverlayEvent();
			}
			else
			{
				m_overlay.updateOverlayCounter();
			}

			if (m_bonusPhase)
			{
				m_bonusPhase = false;
				m_nextBonusPhaseIn = rand() % 3 + 5;
			}
			else
			{
				--m_nextBonusPhaseIn;
				if (m_nextBonusPhaseIn == 0)
					m_bonusPhase = true;
			}

			m_player.increaseMoney(m_MONEY_PER_ROUND * (m_spawners.getDifficulty() + 1));
			m_spawners.increaseDifficulty();
			m_turretPositioningManager.increaseDifficulty();
			// Shop phase duration
			m_nextRoundIn = m_NEXT_ROUND_IN;
			m_gamePhase = false;
		}
	}
	else
	{
		m_nextRoundIn -= dt;
		m_view.setNextRoundIn(m_nextRoundIn > 0.0 ? (int)m_nextRoundIn : 0.0);
		if (m_nextRoundIn <= 0)
		{
			m_gamePhase = true;
			m_spawners.giveToken();
		}

		// Shop phase
		if (!m_shopPhase)
		{
			m_shopPhase = true;
			m_view.showShopButton();
			m_view.showShop();
		}

		// turret Positioning
		if (m_turretIsSelected)
		{
			// todo : finish it (WIP)

			// fin the closest point
			sf::Vector2f mousePosition(sf::Mouse::getPosition(*StateMachine::Instance()->window));

			std::vector<sf::Vector2f> m_points = m_turretPositioningManager.getPositions();

			unsigned index = MathHelper::getClosestPoint(mousePosition,
			                                             m_turretPositioningManager.getPositions());

			m_currentPosition = m_points[index];
		}
	}

	m_player.update(dt);
	m_screenElapsed += dt;
	if (m_screenElapsed >= m_TIME_SCREEN_SWAP)
	{
		m_screen.nextTexture();
		m_screenElapsed = 0.0;
	}

	// VIEW
	m_view.setHitPoint(m_player.getLife());
	m_view.setMoney(m_player.get$Money$());
	m_view.setDifficulty(m_spawners.getDifficulty() + 1);
	m_view.update(dt);
}

void GameState::draw(sf::RenderWindow& window)
{
	m_world.addDrawable(&m_player.getDrawable());

	for (int i = 0; i < (int) m_turrets.size(); i++)
	{
		m_world.addDrawable(&m_turrets[i]->getDrawable());
	}

	for (int i = 0; i < (int) m_projectiles.size(); i++)
	{
		m_world.addDrawable(&m_projectiles[i]->getDrawable());
	}

	m_world.addDrawable(&m_screen);

	m_world.draw(window);

	if (m_turretIsSelected)
	{
		m_turretPositioningManager.draw(window, m_turretSelected->getDrawable());

		// in selection, not draw at 100%
		m_turretSelected->getDrawable().getSprite().setColor(sf::Color(255, 255, 255, 125));

		m_turretSelected->getDrawable().getSprite().setPosition(m_currentPosition);
		window.draw(m_turretSelected->getDrawable().getSprite());
	}

	m_clickEffect.draw(window);
    m_view.draw(&window);
    if(m_bonusPhase)
        m_view.showBonusPhase();
    else
        m_view.hideBonusPhase();
    if(m_gamePhase && m_overlay.isOverlayPhase())
    {
        m_view.showOverlay(std::string(1, m_overlay.getCharFromKeyCode()), m_overlay.getRandomMessage());
    }
    else
    {
        m_view.hideOverlay();
    }
}

bool GameState::onEnter()
{
	MusicManager::Instance()->FadeInOut(1.0, "MENU");

	reset();

	return true;
}

bool GameState::onExit()
{
	for (unsigned i = 0; i < m_demoniacObjects.size(); ++i)
		delete m_demoniacObjects[i];
	m_demoniacObjects.clear();

	return true;
}

void GameState::reset()
{
	// Init the game
	for (unsigned i = 0; i < m_demoniacObjects.size(); ++i)
		delete m_demoniacObjects[i];
	m_demoniacObjects.clear();

	m_gamePhase = true;
	m_nextBonusPhaseIn = rand() % (m_NEXT_BONUS_PHASE_MAX - m_NEXT_BONUS_PHASE_MIN + 1) + m_NEXT_BONUS_PHASE_MIN;
	m_bonusPhase = false;
	m_nextRoundIn = 0.0;
	m_screen = Drawable();
	m_screenElapsed = 0.0;
	m_overlay.prepareNextOverlayEvent();

	// Init the player
	m_player = Player(150);
	m_player.getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("GEEK_1"));
	m_player.getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("GEEK_2"));
	m_player.getDrawable().nextTexture();
	m_player.getDrawable().getSprite().setPosition(sf::Vector2f(617.0f, 237.0f));

	m_world = World();

	// Micro animation for screen
	m_screen.addTexture(Container<sf::Texture>::Instance()->GetResource("SCREEN_1"));
	m_screen.addTexture(Container<sf::Texture>::Instance()->GetResource("SCREEN_2"));
	m_screen.nextTexture();
	m_screen.getSprite().setPosition(sf::Vector2f(603.0f, 139.0f));

	m_spawners = Spawner(m_player.getPosition());
	m_spawners.giveToken();

	// 1280 / 768
	m_spawners.setPosition(sf::Vector2f(1280, 700));
	m_spawners.addPath(Path(1280.0f, 700.0f, 835.0f, 675.0f));
	m_spawners.addPath(Path(835.0f, 675.0f, 785.0f, 550.0f));
	m_spawners.addPath(Path(785.0f, 550.0f, 560.0f, 555.0f));
	m_spawners.addPath(Path(560.0f, 555.0f, 480.0f, 720.0f));
	m_spawners.addPath(Path(480.0f, 720.0f, 190.0f, 660.0f));
	m_spawners.addPath(Path(190.0f, 660.0f, 135.0f, 350.0f));
	m_spawners.addPath(Path(135.0f, 350.0f, 270.0f, 365.0f));
	m_spawners.addPath(Path(270.0f, 365.0f, 365.0f, 540.0f));
	m_spawners.addPath(Path(365.0f, 540.0f, 605.0f, 355.0f));
	m_spawners.addPath(Path(605.0f, 355.0f, 870.0f, 450.0f));
	m_spawners.addPath(Path(870.0f, 450.0f, 1200.0f, 360.0f));
	m_spawners.addPath(Path(1200.0f, 360.0f, 1115.0f, 235.0f));
	m_spawners.addPath(Path(1115.0f, 235.0f, 620.0f, 200.0f));

	m_world.addBackground(Container<sf::Texture>::Instance()->GetResource("BACKGROUND"));

	//m_turrets.push_back(new Poison(sf::Vector2f(250, 530)));
}

int GameState::getScore() {
	return m_spawners.getDifficulty()+1;
}

