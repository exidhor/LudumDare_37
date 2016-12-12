//
// Created by Kraghan on 12/12/2016.
//

#include "Player/Ion.hpp"
#include <Memory/Container.hpp>
#include <Player/IonShoot.hpp>

Ion::Ion(sf::Vector2f const &position)
        : Turret(TIME_BETWEEN_SHOT_ION, TARGETING_RANGE_ION, SHOOTING_RANGE_ION)
{
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("ION_IDLE"));
	getDrawable().nextTexture();
	getDrawable().getSprite().setPosition(position);

	m_canon.addTexture(Container<sf::Texture>::Instance()->GetResource("ION_CANON"));
}

Projectile* Ion::getProjectile(sf::Vector2f const &target)
{
    // orientate the canon
	float angle = Movement::getOrientation(Movement::offset(getDrawable().getSprite().getPosition(),
										   target));

	getDrawable().getSprite().setRotation(angle);
	
	sf::Transform tr;
	tr.rotate(angle);
	m_endCanon = tr.rotate(angle).transformPoint(m_endCanon);
	
	Projectile *projectile = new IonShoot();

    projectile->getDrawable().getSprite().setPosition(target);

    return projectile;
}