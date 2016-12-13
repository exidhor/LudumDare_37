#pragma once
#include "DemoniacObject/DemoniacObject.hpp"

#define MOM_LIFE 10000
#define MOM_SPEED 1.5f
#define MOM_DAMAGE 150
#define MOM_ARMOR 0
#define MOM_SPRITESWAP 1.5f
#define MOM_INCOME 10000

class Mom : public DemoniacObject
{
public :
	Mom();

	virtual void update(double dt);

private :
};
