#include "DemoniacObject/DemoniacObject.hpp"

DemoniacObject::DemoniacObject(sf::Vector2f const& startPosition,
							   int life,
							   float speed,
							   int strength,
							   int armor)
	: Unit(life)
	,PathFollower(startPosition)
    ,m_damage(strength)
    ,m_armor(armor)
	,m_speed(speed)
	,m_elapsedSinceLastSpriteSwap(0.0)
	,m_spriteSwapTreshold(0.25)
	,m_deathTreshold(1.0)
	,m_deathElapsed(0.0)
	,m_toRemove(false)
{
	// nothing
}

void DemoniacObject::suicide(Unit* target)
{
	if(target)
	{
		target->hit(m_damage);
	}
}

bool DemoniacObject::hit(int damage)
{
	int realDamage = damage - m_armor;
	if(realDamage < 0)
	{
		m_life -= realDamage;
	}
	return isDead();
}

void DemoniacObject::setDamage(int strength)
{
	m_damage = strength;
}

void DemoniacObject::setSpeed(float speed)
{
	m_speed = speed;
}

void DemoniacObject::setArmor(int armor)
{
	m_armor = armor;
}

void DemoniacObject::modifyArmor(int modification)
{
	m_armor += modification;
}

int DemoniacObject::getDamage() const
{
	return m_damage;
}

float DemoniacObject::getSpeed() const
{
	return m_speed;
}

int DemoniacObject::getArmor() const
{
	return m_armor;
}

sf::Vector2f const &DemoniacObject::getPosition() const
{
	return getCurrentPosition();
}

bool DemoniacObject::toRemove()
{
	return m_toRemove;
}

void DemoniacObject::update(double dt)
{
	if(!isDead())
	{
		move(getCurrentPosition(),getSpeed());
		currentSprite->setPosition(getCurrentPosition());

		m_elapsedSinceLastSpriteSwap+=dt;
		if(m_elapsedSinceLastSpriteSwap >= m_spriteSwapTreshold)
		{
			nextSprite();
			m_elapsedSinceLastSpriteSwap = 0.0;
		}
	}
	else
	{
		activeDeathSprite();
		if(m_deathElapsed >= m_deathTreshold)
		{
			m_toRemove = true;
		}
	}
}
