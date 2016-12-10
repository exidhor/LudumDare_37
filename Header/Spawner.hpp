#pragma once
#include "DemoniacObject/DemoniacObject.hpp"
#include "DemoniacObject/Fly.hpp"

class Spawner
{
public:
	Spawner(sf::Vector2f const& target);

	void updateTime(double time);

	bool isReadyToSpawn() const;

	DemoniacObject* spawn();

	void setDifficulty(unsigned difficulty);
	
	void increaseDifficulty();

	void setTimeBetweenSpawn(double time);

	void setPosition(sf::Vector2f const& position);

	sf::Vector2f const& getPosition() const;

private:
	sf::Vector2f m_position;

	unsigned m_difficulty;

	bool m_itsTimeToSpawn;

	double m_timeUntilSpawn;

#define DEFAULT_STARTING_SPAWN_TIME 5
	// in seconde
	double m_timeBetweenSpawn;

	std::vector <Path> m_route;
};