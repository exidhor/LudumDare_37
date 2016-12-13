//
// Created by Kraghan on 12/12/2016.
//

#include "Player/Ion.hpp"
#include <Memory/Container.hpp>
#include <Player/IonShoot.hpp>

Ion::Ion(sf::Vector2f const &position)
        : Turret(TIME_BETWEEN_SHOT_ION, TARGETING_RANGE_ION, SHOOTING_RANGE_ION)
{
    m_drawable.addTexture(Container<sf::Texture>::Instance()->GetResource("ION_IDLE"));
	m_drawable.nextTexture();
	m_drawable.getSprite().setPosition(position);

	m_canon.addTexture(Container<sf::Texture>::Instance()->GetResource("ION_CANON"));
	m_canon.setLayer(CANON_LAYER);
	m_canon.nextTexture();
}

Projectile* Ion::getProjectile(sf::Vector2f const &target)
{
    // orientate the canon
	float angle = Movement::getOrientation(Movement::offset(m_drawable.getSprite().getPosition(),
										   target));

#define PI 3.1415926535f
	angle *= 180 / PI;

	m_canon.getSprite().setRotation(angle);

	sf::Vector2f centerOfRotation;

	sf::FloatRect globalBounds = m_canon.getSprite().getGlobalBounds();

	centerOfRotation.x = globalBounds.left + globalBounds.width / 2;
	centerOfRotation.y = globalBounds.top + globalBounds.height / 2;

	m_endCanon = MathHelper::rotatePoint(m_endCanon, centerOfRotation, angle);

	Projectile *projectile = new IonShoot(m_endCanon, target, angle);

    projectile->getDrawable().getSprite().setPosition(m_endCanon);

    return projectile;
}

std::vector<Drawable*> Ion::getDrawables()
{
	std::vector<Drawable*> res = Turret::getDrawables();
	res.push_back(&m_canon);

	return res;
}