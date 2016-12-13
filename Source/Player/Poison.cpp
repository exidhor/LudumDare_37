//
// Created by renaud on 10/12/16.
//

#include <Memory/Container.hpp>
#include <Player/Pschit.hpp>
#include "Player/Poison.hpp"

Poison::Poison(sf::Vector2f const &position)
    : Turret(TIME_BETWEEN_SHOT, TARGETING_RANGE, SHOOTING_RANGE)
{
	m_drawable.addTexture(Container<sf::Texture>::Instance()->GetResource("TURRET_IDLE"));
	m_drawable.addTexture(Container<sf::Texture>::Instance()->GetResource("TURRET_SHOOT"));
	m_drawable.nextTexture();
	getDrawable().getSprite().setPosition(position);
}

Projectile* Poison::getProjectile(sf::Vector2f const &target)
{
    Projectile *projectile = new Pschit();

	projectile->getDrawable().getSprite().setPosition(target);

    return projectile;
}