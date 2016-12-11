#include "Player/ClickEffect.hpp"


ParticuleEffect::ParticuleEffect()
{
	m_timeToDie = TIME_EFFECT;
	m_increaseScaleSpeed = (1 - STARTING_SCALE) / TIME_EFFECT;
}

void ParticuleEffect::update(double dt)
{
	m_currentTime += dt;
	m_currentScale = m_increaseScaleSpeed * m_currentTime;

	sf::Vector2f newScale(m_currentScale, m_currentScale);

	currentSprite->setScale(newScale);
}

bool ParticuleEffect::isDead() const
{
	return m_currentTime > m_timeToDie;
}

// ------------------------------------------------------

ClickEffect::ClickEffect()
{
	// nothing
}

void ClickEffect::update(double time)
{
	for(unsigned i = 0; i < m_particules.size(); i++)
	{
		m_particules[i].update(time);

		if(m_particules[i].isDead())
		{
			m_particules.erase(m_particules.begin() + i);
			i--;
		}
	}
}

void ClickEffect::addEffect(sf::Vector2f const& position)
{
	sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
	sprite->setPosition(position);
	sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("CLICK_EFFECT"));
	sprite->setScale(STARTING_SCALE, STARTING_SCALE);

	m_particules.push_back(ParticuleEffect());

	m_particules.back().addSprite(sprite);
	m_particules.back().nextSprite();
}

void ClickEffect::draw(sf::RenderTarget & target)
{
	for(unsigned i = 0; i < m_particules.size(); i++)
	{
		target.draw(*m_particules[i].currentSprite);
	}
}