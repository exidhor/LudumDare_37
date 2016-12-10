//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_PLAYER_HPP
#define LUDUMDARE_PLAYER_HPP


#include <Behavior/Unit.hpp>

class Player : public Unit
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
    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    unsigned long long m_$lotOfMoney$;

};


#endif //LUDUMDARE_PLAYER_HPP
