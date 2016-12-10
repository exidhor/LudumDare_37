#pragma once
#include "Behavior/Unit.hpp"
#include "Behavior/Movable.hpp"
#include "Behavior/Shooter.hpp"


class DemoniacObject : public Unit, public Movable, public Shooter
{
public :
	DemoniacObject();



private :
	int m_speed;
};