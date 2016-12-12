#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Graphics/Drawable.hpp"

#define INCREASE_TIER_SPEED 3

#define NUMBER_POSITION_UNLOCKED_TIER_0 3
#define NUMBER_POSITION_UNLOCKED_TIER_1 2
#define NUMBER_POSITION_UNLOCKED_TIER_2 1
#define NUMBER_POSITION_UNLOCKED_TIER_3 1
#define NUMBER_POSITION_UNLOCKED_TIER_4 1
#define NUMBER_POSITION_UNLOCKED_TIER_5 1

#define MAX_TIER 5

class TurretPositioning
{
public :
	TurretPositioning();

	void increaseDifficulty();

	std::vector<sf::Vector2f> const& getPositions();

	void draw(sf::RenderTarget & renderTarget, Drawable & turret);

private:
	bool unlockedTier();

	unsigned m_difficulty;
	unsigned m_tier;

	std::vector<sf::Vector2f> m_allPositions;
	std::vector<sf::Vector2f> m_unlockedPositions;
	std::vector<unsigned> m_tierIndices;
};