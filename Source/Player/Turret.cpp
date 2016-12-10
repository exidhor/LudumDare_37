#include "Player/Turret.hpp"

Turret::Turret(double targetingRange, double shootingRange)
    : m_timeUntilShoot(0),
      m_isTimeToShoot(true),
      m_isShooting(false),
      m_targetingRange(targetingRange),
      m_shootingRange(shootingRange)
{
    // nothing
}

double Turret::getTargetingRange() const
{
    return m_targetingRange;
}

double Turret::getShootingRange() const
{
    return m_shootingRange;
}