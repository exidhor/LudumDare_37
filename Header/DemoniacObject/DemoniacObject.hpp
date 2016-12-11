#pragma once

#include <Utils/Updatable.hpp>
#include "Behavior/Unit.hpp"
#include "Behavior/PathFollower.hpp"
#include "Behavior/Suicidable.hpp"
#include "Graphics/Drawable.hpp"


class DemoniacObject : public Unit, public PathFollower, public Suicidable, public Updatable
{
public :
	DemoniacObject(sf::Vector2f const& startPosition,
				   int life, 
				   float speed, 
				   int strength, 
				   int armor,
				   double spriteSwapTreshold);

	virtual ~DemoniacObject() {};

	virtual void suicide(Unit* target);

	bool hit(int damage);

	void setDamage(int strength);
	void setSpeed(float speed);
	void setArmor(int armor);
	void modifyArmor(int modification);

	int getDamage() const;
	float getSpeed() const;
	int getArmor() const;

    virtual sf::Vector2f getPosition() const;

	virtual void update(double dt);

	bool toRemove();

	Drawable & getDrawable();


	double m_elapsedSinceLastSpriteSwap;

protected:
	Drawable m_drawable;

	int m_damage;
	int m_armor;
	float m_speed;
	double m_spriteSwapTreshold;
	double m_deathTreshold;
	double m_deathElapsed;
	bool m_toRemove;
};