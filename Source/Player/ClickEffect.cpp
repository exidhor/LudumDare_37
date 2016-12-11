#include "Player/ClickEffect.hpp"


ParticuleEffect::ParticuleEffect(sf::Vector2f const& position, float orientation)
{
	m_orientation = orientation;
	m_position = position;
	m_currentTime = 0;
	m_timeToDie = TIME_EFFECT;
	m_increaseScaleSpeed = (1 - STARTING_SCALE) / TIME_EFFECT;
}

ParticuleEffect::~ParticuleEffect()
{
	
}

void ParticuleEffect::update(double dt)
{
	m_currentTime += dt;
	m_currentScale = m_increaseScaleSpeed * m_currentTime;

	sf::Vector2f newScale(m_currentScale, m_currentScale);

	m_drawable.getSprite().setScale(newScale);
	m_drawable.getSprite().setOrigin(m_drawable.getSprite().getLocalBounds().width / 2,
									 m_drawable.getSprite().getLocalBounds().height / 2);
	m_drawable.getSprite().setPosition(m_position);
	m_drawable.getSprite().setRotation(m_orientation);
}

bool ParticuleEffect::isDead() const
{
	return m_currentTime > m_timeToDie;
}

Drawable & ParticuleEffect::getDrawable()
{
	return m_drawable;
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
	float orientation = rand() % 360;
	m_particules.push_back(ParticuleEffect(position, orientation));

	m_particules.back().getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("CLICK_EFFECT"));
	m_particules.back().getDrawable().nextTexture();	// generate a random orientation to make a little changement
														// for each effect
}

void ClickEffect::draw(sf::RenderTarget & target)
{
	for(unsigned i = 0; i < m_particules.size(); i++)
	{
		target.draw(m_particules[i].getDrawable().getSprite());
	}
}