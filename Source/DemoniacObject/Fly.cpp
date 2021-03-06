//
// Created by renaud on 10/12/16.
//

#include <Memory/Container.hpp>
#include "DemoniacObject/Fly.hpp"

Fly::Fly()
    : DemoniacObject(sf::Vector2f(), 
					 FLY_LIFE, 
					 FLY_SPEED,
					 FLY_DAMAGE,
					 FLY_ARMOR,
					 FLY_SPRITESWAP)
{
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("FLY_1"));
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("FLY_2"));
	getDrawable().setDeathTexture(Container<sf::Texture>::Instance()->GetResource("FLY_3"));
	getDrawable().nextTexture();
	setKillIncome(FLY_INCOME);
}

SmallFly::SmallFly()
        : DemoniacObject(sf::Vector2f(),
						 FLY_LIFE / 2, 
						 FLY_SPEED * 2, 
						 FLY_DAMAGE - FLY_DAMAGE / 2, 
						 FLY_ARMOR, 
						 FLY_SPRITESWAP)
{
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("SMALL_FLY_1"));
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("SMALL_FLY_2"));
	getDrawable().setDeathTexture(Container<sf::Texture>::Instance()->GetResource("SMALL_FLY_3"));
	getDrawable().nextTexture();
    setKillIncome(FLY_INCOME + 2);
}

FatFly::FatFly()
        : DemoniacObject(sf::Vector2f(), 
						 FLY_LIFE * 2, 
						 FLY_SPEED / 2,
						 FLY_DAMAGE + FLY_DAMAGE / 2, 
						 FLY_ARMOR,
						 FLY_SPRITESWAP)
{
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("FAT_FLY_1"));
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("FAT_FLY_2"));
	getDrawable().setDeathTexture(Container<sf::Texture>::Instance()->GetResource("FAT_FLY_3"));
	getDrawable().nextTexture();
    setKillIncome(FLY_INCOME + 5);
}
