#pragma once

#include "Behavior/Unit.hpp"
#include "Behavior/PathFollower.hpp"
#include "Behavior/Suicidable.hpp"
#include "Graphics/Drawable.hpp"


class DemoniacObject : public Unit, public PathFollower, public Suicidable, public Drawable
{
public :
	DemoniacObject(sf::Vector2f const& startPosition, 
				   int life, 
				   float speed, 
				   int strength, 
				   int armor);

	virtual void suicide(Unit* target);

	bool hit(int damage);

	void setDamage(int strength);
	void setSpeed(float speed);
	void setArmor(int armor);
	void modifyArmor(int modification);

	int getDamage() const;
	float getSpeed() const;
	int getArmor() const;

    sf::Vector2f const& getPosition() const
    {
        return currentSprite->getPosition();
    }

private :
	int m_damage;
	int m_armor;

	float m_speed;
};