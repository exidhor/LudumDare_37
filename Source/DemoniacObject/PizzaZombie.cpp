//
// Created by Kraghan on 11/12/2016.
//

#include "DemoniacObject/PizzaZombie.hpp"
#include <Memory/Container.hpp>

PizzaZombie::PizzaZombie()
        : DemoniacObject(sf::Vector2f(),
                         PIZZA_LIFE,
                         PIZZA_SPEED,
                         PIZZA_DAMAGE,
                         PIZZA_ARMOR,
                         PIZZA_SPRITESWAP)
{
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PIZZA_1"));
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PIZZA_2"));
    getDrawable().setDeathTexture(Container<sf::Texture>::Instance()->GetResource("PIZZA_3"));
    getDrawable().nextTexture();
}

FatPizzaZombie::FatPizzaZombie()
        : DemoniacObject(sf::Vector2f(),
                         PIZZA_LIFE*2,
                         PIZZA_SPEED/2,
                         PIZZA_DAMAGE*4,
                         PIZZA_ARMOR*2,
                         PIZZA_SPRITESWAP)
{
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("FAT_PIZZA_1"));
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("FAT_PIZZA_2"));
    getDrawable().setDeathTexture(Container<sf::Texture>::Instance()->GetResource("FAT_PIZZA_3"));
    getDrawable().nextTexture();
}

SmallPizzaZombie::SmallPizzaZombie()
        : DemoniacObject(sf::Vector2f(),
                         PIZZA_LIFE/2,
                         PIZZA_SPEED*2,
                         PIZZA_DAMAGE/4,
                         PIZZA_ARMOR/2,
                         PIZZA_SPRITESWAP)
{
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("SMALL_PIZZA_1"));
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("SMALL_PIZZA_2"));
    getDrawable().setDeathTexture(Container<sf::Texture>::Instance()->GetResource("SMALL_PIZZA_3"));
    getDrawable().nextTexture();
}