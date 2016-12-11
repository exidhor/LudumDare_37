#include "Player/Projectile.hpp"

Projectile::Projectile(float speed, int damage)
	: m_speed(speed),
	  m_damage(damage),
      m_timeTreshold(0.3),
      m_timeElapsed(0),
      m_toRemove(false)
{
	// nothing
}

void Projectile::update(double time)
{
    sf::Vector2f position = m_drawable.getSprite().getPosition();
    sf::Vector2f movement = move(position, m_speed);
    m_drawable.nextTexture();
	m_drawable.getSprite().setPosition(movement);

    m_timeElapsed += time;
    if (m_timeElapsed >= m_timeTreshold)
    {
        m_toRemove = true;
    }
}

float Projectile::getDamage() const
{
    return m_damage;
}

Drawable & Projectile::getDrawable()
{
	return m_drawable;
}

bool Projectile::toRemove() const
{
    return m_toRemove;
}