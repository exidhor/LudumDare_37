#include "Spawner.hpp"

Spawner::Spawner()
	: m_difficulty(0)
	, m_itsTimeToSpawn(false)
	, m_timeUntilSpawn(DEFAULT_STARTING_SPAWN_TIME)
	, m_timeBetweenSpawn(DEFAULT_STARTING_SPAWN_TIME)
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
	if(m_timeUntilSpawn)
	{
		//return new Fly();
		// todo
	}

	return nullptr;
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