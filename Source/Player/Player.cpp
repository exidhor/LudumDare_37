//
// Created by Kraghan on 10/12/2016.
//

#include <GameState/StateMachine.hpp>
#include "Player/Player.hpp"

/* Explicit */ Player::Player(int life)
: Unit(life)
, m_$lotOfMoney$(1000)
{
    // None
}

/* Virtual */ Player::~Player()
{

}

void Player::increaseMoney(unsigned long long $money$)
{
    m_$lotOfMoney$ += $money$;
}

unsigned long long Player::get$Money$()
{
    return m_$lotOfMoney$;
}

/* Virtual */ bool Player::hit(int damage)
{
    m_life-=damage;
    if(m_life <= 0)
    {
        // TODO set game over
        //StateMachine::changeChange(GameOverState::Instance());
        return true;
    }
    return false;
}


