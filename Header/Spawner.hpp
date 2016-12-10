#pragma once
#include "DemoniacObject/DemoniacObject.hpp"
#include "DemoniacObject/Fly.hpp"

class Spawner
{
public:
	Spawner();

	void updateTime(double time);

	DemoniacObject* spawn();

	void setDifficulty(unsigned difficulty);
	
	void increaseDifficulty();

	void setTimeBetweenSpawn(double time);


private:
	unsigned m_difficulty;

	bool m_itsTimeToSpawn;

	double m_timeUntilSpawn;

#define DEFAULT_STARTING_SPAWN_TIME 5
	// in seconde
	double m_timeBetweenSpawn;
};