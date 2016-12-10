#pragma once
#include "DemoniacObject.hpp"

class Spawner
{
public:
	Spawner();

	DemoniacObject* spawn();

	void setDifficulty(unsigned difficulty);
	
	void increaseDifficulty();

	void setTimeBetweenSpawn(double time);


private:
	unsigned m_difficulty;

	double m_timeUntilSpawn;

	double m_timeBetweenSpawn;
};
