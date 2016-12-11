#include "Spawner.hpp"
#include "Memory/PoolAllocator.hpp"
#include <iostream>
#include <DemoniacObject/PizzaZombie.hpp>

Spawner::Spawner(sf::Vector2f const& target)
	: m_difficulty(0)
	, m_itsTimeToSpawn(false)
	, m_timeUntilSpawn(DEFAULT_STARTING_SPAWN_TIME)
	, m_timeBetweenSpawn(DEFAULT_STARTING_SPAWN_TIME)
	, m_target(target)
    , m_token(0)
{
	// nothing
}

void Spawner::updateTime(double time)
{
	m_timeUntilSpawn -= time;

	while(m_timeUntilSpawn <= 0)
	{
		m_timeUntilSpawn = m_timeBetweenSpawn - m_timeUntilSpawn;
		m_itsTimeToSpawn = true;
	}
}

DemoniacObject* Spawner::spawn()
{
	if(m_itsTimeToSpawn)
	{
		m_itsTimeToSpawn = false;

        int token = rand() % m_token;

        token = getHighestTokenCost(token);

        DemoniacObject * ptr = createDemoniacObjectWithToken(token);

        m_token-=token;

        // ajout du path
        for(unsigned i = 0; i < m_route.size(); i++)
        {
            ptr->addPath(m_route[i]);
        }
        ptr->setCurrentPath(&m_route[0]);

        return ptr;

	}

	return nullptr;
}

bool Spawner::isReadyToSpawn() const
{
	return m_itsTimeToSpawn;
}

void Spawner::setDifficulty(unsigned difficulty)
{
	m_difficulty = difficulty;
}

void Spawner::increaseDifficulty()
{
	m_difficulty++;
}

void Spawner::setTimeBetweenSpawn(double time)
{
	m_timeBetweenSpawn = time;
}

void Spawner::setPosition(sf::Vector2f const& position)
{
	m_position = position;
	m_route.clear();
}

sf::Vector2f const& Spawner::getPosition() const
{
	return m_position;
}

void Spawner::addPath(Path path)
{
    m_route.push_back(path);
}

unsigned Spawner::getDifficulty()
{
    return m_difficulty;
}

bool Spawner::outOfToken()
{
    return m_token <= 0;
}

void Spawner::giveToken()
{
    m_token = (long) (10 + m_difficulty * 10);
}

int Spawner::getHighestTokenCost(int token)
{
    // Respecter la hierarchie ! Du plus grand au plus petit !

    if(token >= 60)
        return 60;
    if(token >= 40)
        return 40;
    if(token >= 30)
        return 30;
    if(token >= 15)
        return 15;
    else if(token >= 5)
        return 5;
    else
        return 1;
}

DemoniacObject *Spawner::createDemoniacObjectWithToken(int token)
{
    switch(token)
    {
        case 1 :
			return new Fly();
        case 5 :
            return new FatFly();
        case 15 :
            return new PizzaZombie();
        case 30 :
            return new SmallFly();
        case 40 :
            return new SmallPizzaZombie();
        case 60 :
            return new FatPizzaZombie();
        default:
        std::cerr<< "Unknown token value : " << token << std::endl;
			return new Fly();
    }
}

