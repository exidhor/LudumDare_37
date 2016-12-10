#include "Spawner.hpp"
#include "Memory/PoolAllocator.hpp"

Spawner::Spawner(sf::Vector2f const& target)
	: m_difficulty(0)
	, m_itsTimeToSpawn(false)
	, m_timeUntilSpawn(DEFAULT_STARTING_SPAWN_TIME)
	, m_timeBetweenSpawn(DEFAULT_STARTING_SPAWN_TIME)
{
	// nothing
	m_route.push_back(Path(m_position, target));
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
		DemoniacObject* ptr = PoolAllocator<Fly>::Instance()->Allocate();
		
		// ajout du path
		for(unsigned i = 0; i < m_route.size(); i++)
		{
			ptr->addPath(m_route[i]);
		}
		ptr->setCurrentPath(&m_route[0]);

		return ptr;
	}

	m_itsTimeToSpawn = false;

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
}

sf::Vector2f const& Spawner::getPosition() const
{
	return m_position;
}