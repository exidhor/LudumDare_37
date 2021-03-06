#pragma once
#include "DemoniacObject/DemoniacObject.hpp"
#include "DemoniacObject/Fly.hpp"
#include <iostream>
#include <DemoniacObject/PizzaZombie.hpp>
#include "DemoniacObject/PaperPlane.hpp"
#include "DemoniacObject/Mom.hpp"

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

	void addPath(Path path);

    unsigned getDifficulty();

    bool outOfToken();

    void giveToken();

private:
	sf::Vector2f m_position;
	sf::Vector2f m_target;

	unsigned m_difficulty;

	bool m_itsTimeToSpawn;

	double m_timeUntilSpawn;

    long m_token;

#define DEFAULT_STARTING_SPAWN_TIME 1
	// in seconde
	double m_timeBetweenSpawn;

	std::vector <Path> m_route;

    int getHighestTokenCost(int token);

    DemoniacObject* createDemoniacObjectWithToken(int token);

};