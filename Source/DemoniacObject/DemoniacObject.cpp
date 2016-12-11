#include "DemoniacObject/DemoniacObject.hpp"
#include "MathHelper.hpp"

DemoniacObject::DemoniacObject(sf::Vector2f const& startPosition,
							   int life,
							   float speed,
							   int strength,
							   int armor,
                               double spriteSwapTreshold)
	: Unit(life)
	,PathFollower(startPosition)
    ,m_damage(strength)
    ,m_armor(armor)
	,m_speed(speed)
	,m_elapsedSinceLastSpriteSwap(0.0)
	,m_spriteSwapTreshold(spriteSwapTreshold)
	,m_deathTreshold(3.0f)
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
	if(damage > m_armor)
		m_life -= (damage - m_armor);
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

sf::Vector2f DemoniacObject::getPosition() const
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
		m_elapsedSinceLastSpriteSwap+=dt;
		if(m_elapsedSinceLastSpriteSwap >= m_spriteSwapTreshold)
		{
			m_drawable.nextTexture();
			m_elapsedSinceLastSpriteSwap = 0.0;
		}
		sf::Vector2f movement = move(getCurrentPosition(),getSpeed());

		m_drawable.getSprite().setPosition(getCurrentPosition());

	#define PI 3.141592653589793
		m_drawable.getSprite().setRotation(Movement::getOrientation(movement)*180/PI);

		if (getCurrentPath() == nullptr)
		{
			m_life = 0;
		}
	}
	else
	{
		m_drawable.activeDeathSprite();
		m_deathElapsed+=dt;

		// fondu
		sf::Color color = m_drawable.getSprite().getColor();
		color.a = fabsf(m_deathElapsed - m_deathTreshold) / m_deathTreshold * 255;
		m_drawable.getSprite().setColor(color);

		if(m_deathElapsed >= m_deathTreshold)
		{
			m_toRemove = true;
		}
	}
}

Drawable & DemoniacObject::getDrawable()
{
	return m_drawable;
}