//
// Created by renaud on 10/12/16.
//

#include <Memory/PoolAllocator.hpp>
#include <Memory/Container.hpp>
#include <Player/Pschit.hpp>
#include "Player/Poison.hpp"

Poison::Poison(sf::Vector2f const &position)
    : Turret(TIME_BETWEEN_SHOT, TARGETING_RANGE, SHOOTING_RANGE)
{
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("TURRET_IDLE"));
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("TURRET_SHOOT"));
    getDrawable().nextTexture();
	getDrawable().getSprite().setPosition(position);
}

Projectile* Turret::getProjetile(sf::Vector2f const &target)
{
    Projectile *projectile = new Pschit();

	projectile->getDrawable().getSprite().setPosition(target);

    return projectile;
}