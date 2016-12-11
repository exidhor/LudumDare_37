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