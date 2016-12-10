#include "Player/Turret.hpp"

Turret::Turret(float timeBetWeenShoot, float targetingRange, float shootingRange)
    : m_timeUntilShoot(0),
      m_isTimeToShoot(true),
      m_isShooting(false),
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
    world.getDemoniacObjectIn(currentSprite->getPosition(), m_targetingRange, targets);

    std::vector<sf::Vector2f> points;
    for (int i = 0; i < (int) targets.size(); i++)
    {
        points.push_back(targets[i]->getCurrentPosition());
    }

    int nearest = MathHelper::getClosestPoint(currentSprite->getPosition(), points);
    shoot(points[nearest]);
}

Projectile* Turret::shoot(sf::Vector2f const &target)
{
    if (m_isTimeToShoot)
    {
        m_isTimeToShoot = false;
        m_timeUntilShoot = m_timeBetweenShoot;

        return getProjetile(target);
    }

    return nullptr;
}
