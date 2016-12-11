//
// Created by renaud on 11/12/16.
//

#include <Memory/PoolAllocator.hpp>
#include <Memory/Container.hpp>
#include "Player/Pschit.hpp"

Pschit::Pschit()
    : Projectile(SPEED, DAMAGE, TIME_BETWEEN_SWAP)
{
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PSCHIT_1"));
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PSCHIT_2"));
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PSCHIT_3"));
	getDrawable().nextTexture();
}

sf::Vector2f Pschit::move(sf::Vector2f const &position, float speed)
{
    return position;
}