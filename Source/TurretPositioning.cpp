#include "TurretPositioning.hpp"

TurretPositioning::TurretPositioning()
{
	m_difficulty = 0;
	m_tier = 0;

	// init hard coded position
	m_allPositions.push_back(sf::Vector2f(905, 750));
	m_allPositions.push_back(sf::Vector2f(675, 690));
	m_allPositions.push_back(sf::Vector2f(425, 620));

	m_allPositions.push_back(sf::Vector2f(105, 695));
	m_allPositions.push_back(sf::Vector2f(250, 530));

	m_allPositions.push_back(sf::Vector2f(360, 365));

	m_allPositions.push_back(sf::Vector2f(630, 485));
	
	m_allPositions.push_back(sf::Vector2f(950, 350));
	
	m_allPositions.push_back(sf::Vector2f(1225, 285));

	// init tiers
	m_tierIndices.push_back(NUMBER_POSITION_UNLOCKED_TIER_0);
	m_tierIndices.push_back(NUMBER_POSITION_UNLOCKED_TIER_1);
	m_tierIndices.push_back(NUMBER_POSITION_UNLOCKED_TIER_2);
	m_tierIndices.push_back(NUMBER_POSITION_UNLOCKED_TIER_3);
	m_tierIndices.push_back(NUMBER_POSITION_UNLOCKED_TIER_4);
	m_tierIndices.push_back(NUMBER_POSITION_UNLOCKED_TIER_5);

	// init first unlockedPosition
	for(unsigned i = 0; i < m_tierIndices[0]; i++)
	{
		m_unlockedPositions.push_back(m_allPositions[i]);
	}
}

void TurretPositioning::increaseDifficulty()
{
	m_difficulty++;

	if(unlockedTier() && m_tier < MAX_TIER)
	{
		m_tier++;
		unsigned numberPositionToUnlocked = m_tierIndices[m_tier];

		for(unsigned i = m_unlockedPositions.size(); i < m_unlockedPositions.size() + numberPositionToUnlocked; i++)
		{
			m_unlockedPositions.push_back(m_allPositions[i]);
		}
	}
}

std::vector<sf::Vector2f> const& TurretPositioning::getPositions()
{
	return m_unlockedPositions;
}

bool TurretPositioning::unlockedTier()
{
	if(m_difficulty >= 3)
	{
		m_difficulty = 0;
		return true;
	}

	return false;
}

