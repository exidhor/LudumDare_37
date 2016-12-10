#include "Utils/Patch.hpp"
#include "View/GameView.hpp"
#include "Memory/Container.hpp"

/* explicit */ GameView::GameView(bool debug, InputHandler * inputHandler)
: BasicInterface(debug, inputHandler)
{
    m_hitPoint.create("HIT_POINT", 400, 50, 25,
                      Container<sf::Font>::Instance()->GetResource("FONT"),
                      "HIT POINT : ", sf::Color::Black);

    m_money.create("MONEY", 400, 80, 25,
                      Container<sf::Font>::Instance()->GetResource("FONT"),
                      "MONEY : ", sf::Color::Black);

    getContentPane()->addComponent(&m_hitPoint);
    getContentPane()->addComponent(&m_money);
}

/* virtual */ GameView::~GameView()
{
    // None
}

/* virtual */ void GameView::update(double elapsed)
{
    basicUpdate(elapsed);
}

/* virtual */ void GameView::processInput(sf::Event & e)
{
    basicInput(e);
}

/* virtual */ void GameView::draw(sf::RenderWindow * w)
{
    basicDraw(w);
}

void GameView::setHitPoint(int hitPoint)
{
    m_hitPoint.setTexte("HIT POINT : " + fix::to_string(hitPoint));
}

void GameView::setMoney(unsigned long long money)
{
    m_money.setTexte("MONEY : " + fix::to_string(money));
}
