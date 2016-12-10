#pragma once
#include "Behavior/Unit.hpp"

class Suicidable
{
public :
	virtual void suicide(Unit* target) = 0;
};
