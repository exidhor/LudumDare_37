//
// Created by Kraghan on 12/12/2016.
//

#ifndef LUDUMDARE_ION_HPP
#define LUDUMDARE_ION_HPP


#include "Turret.hpp"

#define TIME_BETWEEN_SHOT_ION 5
#define TARGETING_RANGE_ION 30
#define SHOOTING_RANGE_ION 30

class Ion : public Turret
{
public :
    Ion(sf::Vector2f const& position);

    virtual Projectile * getProjectile(sf::Vector2f const &target);

	virtual std::vector<Drawable*> getDrawables();

private:
	Drawable m_canon;
	sf::Vector2f m_endCanon;
};


#endif //LUDUMDARE_ION_HPP
