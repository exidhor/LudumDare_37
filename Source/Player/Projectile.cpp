#include "Player/Projectile.hpp"

Projectile::Projectile(float speed, int damage, double timeBetweenSwap)
	: m_speed(speed),
	  m_damage(damage),
      m_elapsedSinceLastSpriteSwap(0),
      m_spriteSwapTreshold(timeBetweenSwap)
{
	// nothing
}

void Projectile::update(double time)
{
    m_elapsedSinceLastSpriteSwap += time;

    sf::Vector2f position = m_drawable.getSprite().getPosition();
    if (m_elapsedSinceLastSpriteSwap >= m_spriteSwapTreshold)
    {
		m_drawable.nextTexture();
        m_elapsedSinceLastSpriteSwap = 0;
    }
    sf::Vector2f movement = move(position, m_speed);
	m_drawable.getSprite().setPosition(movement);
}

float Projectile::getDamage() const
{
    return m_damage;
}

Drawable & Projectile::getDrawable()
{
	return m_drawable;
}