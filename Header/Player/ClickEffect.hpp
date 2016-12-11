#pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Drawable.hpp"
#include "Memory/PoolAllocator.hpp"
#include "Memory/Container.hpp"

#define STARTING_SCALE 0.1f
#define TIME_EFFECT 0.2f

class ParticuleEffect : public Drawable
{
public:  
	ParticuleEffect();

	void update(double dt);

	bool isDead() const;

private :
	double m_currentTime;
	double m_timeToDie;
	double m_increaseScaleSpeed;
	double m_currentScale;
};

class ClickEffect
{
public :
	ClickEffect();

	void update(double time);

	void addEffect(sf::Vector2f const& position);

	void draw(sf::RenderTarget & target);

private :
	double currentTime;

	std::vector<ParticuleEffect> m_particules;
};
