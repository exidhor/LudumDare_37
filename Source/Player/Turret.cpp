#include "Player/Turret.hpp"

Turret::Turret()
    : m_timeUntilShoot(0),
      m_isTimeToShoot(true),
      m_isShooting(false)
{
    // nothing
}