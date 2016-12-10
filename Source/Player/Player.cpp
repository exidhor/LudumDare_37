//
// Created by Kraghan on 10/12/2016.
//

#include <GameState/StateMachine.hpp>
#include <GameState/GameOverState.hpp>
#include "Player/Player.hpp"

/* Explicit */ Player::Player(int life)
    : Unit(life)
    , m_$lotOfMoney$(1000)
    , m_clickRadius(15.0f)
    , m_damage(5)
    , m_elapsedSinceLastSpriteSwap(0.0)
    , m_spriteSwapTreshold(0.2)
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
        StateMachine::Instance()->pushState(GameOverState::Instance());
        return true;
    }
    return false;
}

sf::Vector2f Player::getPosition() const
{
    return currentSprite->getPosition();
}

float Player::getClickRadius()
{
    return m_clickRadius;
}

int Player::getDamage()
{
    return m_damage;
}

void Player::update(double dt)
{
    m_elapsedSinceLastSpriteSwap+=dt;
    if(m_elapsedSinceLastSpriteSwap >= m_spriteSwapTreshold)
    {
        nextSprite();
        m_elapsedSinceLastSpriteSwap = 0.0;
    }
}