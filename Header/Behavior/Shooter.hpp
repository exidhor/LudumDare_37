#pragma once
#include "Player/Projectile.hpp"
#include "Unit.hpp"
#include "Player/Projectile.hpp"

class Shooter
{
public :
	Shooter()
		: m_target(nullptr)
	{
		// nothing
	}

	virtual Projectile shoot(Unit* target) = 0;

protected:
	Unit* m_target;
};
