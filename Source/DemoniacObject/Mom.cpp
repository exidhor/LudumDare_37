#include "DemoniacObject/Mom.hpp"
#include "Memory/Container.hpp"

Mom::Mom()
	: DemoniacObject(sf::Vector2f(),
					 MOM_LIFE,
					 MOM_SPEED,
					 MOM_DAMAGE,
					 MOM_ARMOR,
					 MOM_SPRITESWAP)
{
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("MOTHER_1"));
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("MOTHER_2"));
	//getDrawable().setDeathTexture(Container<sf::Texture>::Instance()->GetResource("FLY_3"));
	getDrawable().nextTexture();
}

void Mom::update(double dt)
{
	// compute mom speed to simulate the walk
	
	float coef = (MOM_SPRITESWAP - m_elapsedSinceLastSpriteSwap) / MOM_SPRITESWAP;

	if (coef < 0.3)
		coef = 0.3;

	if (coef > 1)
		coef = 1;

	float speed = coef * MOM_SPEED;

	setSpeed(speed);

	DemoniacObject::update(dt);
}