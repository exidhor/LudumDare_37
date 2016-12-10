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

    m_difficulty.create("DIFFICULTY", 400, 110, 25,
                   Container<sf::Font>::Instance()->GetResource("FONT"),
                   "DIFFICULTY : ", sf::Color::Black);

    m_exitButton.create("EXIT_BUTTON", 1160, 10,
                         Container<sf::Texture>::Instance()->GetResource("EXIT_BR"),
                         Container<sf::Texture>::Instance()->GetResource("EXIT_BP"));

    m_optButton.create("OPT_BUTTON", 1030, 10,
                         Container<sf::Texture>::Instance()->GetResource("OPT_BR"),
                         Container<sf::Texture>::Instance()->GetResource("OPT_BP"));

    getContentPane()->addComponent(&m_hitPoint);
    getContentPane()->addComponent(&m_money);
    getContentPane()->addComponent(&m_difficulty);
    getContentPane()->addComponent(&m_exitButton);
    getContentPane()->addComponent(&m_optButton);
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

void GameView::setDifficulty(unsigned int diff)
{
    m_difficulty.setTexte("DIFFICULTY : " + fix::to_string(diff));
}
