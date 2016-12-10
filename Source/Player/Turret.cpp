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

    world.getDemoniacObjectIn(currentSprite->getPosition(), m_shootingRange, targets);
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

float Turret::getTargetingRange() const
{
    return m_targetingRange;
}

float Turret::getShootingRange() const
{
    return m_shootingRange;
}