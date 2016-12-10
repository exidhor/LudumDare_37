//
// Created by renaud on 10/12/16.
//

#include <Memory/PoolAllocator.hpp>
#include <Memory/Container.hpp>
#include "Player/Poison.hpp"

Poison::Poison(sf::Vector2f const &position)
    : Turret()
{
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("TURRET_IDLE"));
    sprite->setPosition(position);
    addSprite(sprite);

    sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*Container<sf::Texture>::Instance()->GetResource("TURRET_SHOOT"));
    sprite->setPosition(position);
    addSprite(sprite);

    nextSprite();
}

void Poison::update(double time)
{
    m_timeUntilShoot -= time;
    m_isTimeToShoot = m_timeUntilShoot <= 0;
    if (m_isShooting)
    {
        m_isShooting = false;
        nextSprite();
    }
}

Projectile* Poison::shoot(sf::Vector2f const &target)
{
    if (m_isTimeToShoot)
    {
        m_isTimeToShoot = false;
        m_timeUntilShoot = TIME_BETWEEN_SHOT;
        m_isShooting = true;
        nextSprite();

        Projectile *projectile = nullptr;

        //TODO - create projectile

        return projectile;
    }

    return nullptr;
}