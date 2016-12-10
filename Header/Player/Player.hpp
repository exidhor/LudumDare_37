//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_PLAYER_HPP
#define LUDUMDARE_PLAYER_HPP

#include "Graphics/Drawable.hpp"
#include <Behavior/Unit.hpp>

class Player : public Unit, public Drawable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Player              (int life);
    virtual             ~Player             ();

    void                increaseMoney       (unsigned long long $money$);
    unsigned long long  get$Money$          ();
    virtual bool        hit                 (int damage);
    float               getClickRadius      ();
    int                 getDamage           ();
    virtual sf::Vector2f getPosition        () const;

    void update(double dt);
    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    unsigned long long  m_$lotOfMoney$;
    float               m_clickRadius;
    int                 m_damage;
    double              m_elapsedSinceLastSpriteSwap;
    double              m_spriteSwapTreshold;

};

#endif //LUDUMDARE_PLAYER_HPP
