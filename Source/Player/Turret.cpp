#include "Player/Turret.hpp"

Turret::Turret(float timeBetWeenShoot, float targetingRange, float shootingRange)
    : m_timeUntilShoot(0),
      m_isTimeToShoot(true),
      m_hasATarget(false),
      m_timeBetweenShoot(timeBetWeenShoot),
      m_targetingRange(targetingRange),
      m_shootingRange(shootingRange)
{
    // nothing
}

void Turret::update(double time, const World world)
{
    m_timeUntilShoot -= time;
    m_isTimeToShoot = m_timeUntilShoot <= 0;

    std::vector<DemoniacObject*> targets;
    world.getDemoniacObjectIn(m_drawable.getSprite().getPosition(), m_targetingRange, targets);

    m_hasATarget = targets.size() > 0;

    if (m_hasATarget)
    {
        std::vector<sf::Vector2f> points;
        for (int i = 0; i < (int) targets.size(); i++) {
            points.push_back(targets[i]->getCurrentPosition());
        }

        int nearest = MathHelper::getClosestPoint(m_drawable.getSprite().getPosition(), points);
        m_nearestTargetPosition = points[nearest];
    }
}

Projectile* Turret::shoot()
{
    if (m_isTimeToShoot && m_hasATarget)
    {
        m_drawable.nextTexture();
        m_isTimeToShoot = false;
        m_timeUntilShoot = m_timeBetweenShoot;

        return getProjectile(m_nearestTargetPosition);
    }

    return nullptr;
}

Drawable & Turret::getDrawable()
{
	return m_drawable;
}