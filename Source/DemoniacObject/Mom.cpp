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
	DemoniacObject::update(dt);

	// compute mom speed to simulate the walk
	float speed = 1 - (MOM_SPRITESWAP - m_elapsedSinceLastSpriteSwap) * MOM_SPEED;
	setSpeed(speed);
}