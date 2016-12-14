#include "Utils/Patch.hpp"
#include "View/GameView.hpp"
#include "Memory/Container.hpp"

/* explicit */ GameView::GameView(bool debug, InputHandler * inputHandler)
: BasicInterface(debug, inputHandler)
{
    m_hitPoint.create("HIT_POINT", 1000, 50, 25,
                      Container<sf::Font>::Instance()->GetResource("FONT"),
                      "HIT POINT : ", sf::Color::Green);

    m_money.create("MONEY", 1000, 80, 25,
                      Container<sf::Font>::Instance()->GetResource("FONT"),
                      "MONEY : ", sf::Color::Green);

    m_nextRoundIn.create("NEXT_ROUND_IN", 1000, 140, 25,
                   Container<sf::Font>::Instance()->GetResource("FONT"),
                   "", sf::Color::Black);

    m_difficulty.create("DIFFICULTY", 1000, 110, 25,
                   Container<sf::Font>::Instance()->GetResource("FONT"),
                   "DIFFICULTY : ", sf::Color::Green);

    m_soundOn.create("SOUND_BUTTON_ON", 398, 75,
                         Container<sf::Texture>::Instance()->GetResource("SOUND_ON_R"),
                         Container<sf::Texture>::Instance()->GetResource("SOUND_ON_P"));

    m_soundOff.create("SOUND_BUTTON_OFF", 398, 75,
                       Container<sf::Texture>::Instance()->GetResource("SOUND_OFF_R"),
                       Container<sf::Texture>::Instance()->GetResource("SOUND_OFF_P"));

    m_BonusPhase.create("BONUS_PHASE", 530, 70, 25,
                        Container<sf::Font>::Instance()->GetResource("FONT"),
                        "", sf::Color::Black);

    m_shopEnter.create("SHOP_ENTER", 775, 82,
                      Container<sf::Texture>::Instance()->GetResource("SHOP_ENTER_P"),
                      Container<sf::Texture>::Instance()->GetResource("SHOP_ENTER_R"));
    // -- SHOP --

    m_overlay.create("OVERLAY", 69, 44,
                        Container<sf::Texture>::Instance()->GetResource("OVERLAY_ALERT"));

    m_overlayToPress.create("OVERLAY_PRESS", 860, 400, 100,
                        Container<sf::Font>::Instance()->GetResource("FONT_OVERLAY"),
                        "", sf::Color(210,0,0));

    m_overlayRandomMessage.create("OVERLAY_MESSAGE", 700,150, 50,
                        Container<sf::Font>::Instance()->GetResource("FONT_OVERLAY"),
                        "",  sf::Color(210,0,0));


    m_overlay.addComponent(&m_overlayRandomMessage);
    m_overlay.addComponent(&m_overlayToPress);

    getContentPane()->addComponent(&m_hitPoint);
    getContentPane()->addComponent(&m_money);
    getContentPane()->addComponent(&m_nextRoundIn);
    getContentPane()->addComponent(&m_difficulty);
    getContentPane()->addComponent(&m_soundOn);
    getContentPane()->addComponent(&m_BonusPhase);
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

void GameView::setNextRoundIn(double nextRoundIn)
{
    m_nextRoundIn.setTexte("Next round in : "+fix::to_string(nextRoundIn));
}

void GameView::hideNextRoundIn()
{
    m_nextRoundIn.setTexte("");
}

void GameView::setDifficulty(unsigned int diff)
{
    m_difficulty.setTexte("DIFFICULTY : " + fix::to_string(diff));
}

void GameView::showBonusPhase()
{
    m_BonusPhase.setTexte("PRESS ANY KEY !");
}

void GameView::hideBonusPhase()
{
    m_BonusPhase.setTexte("");
}

void GameView::showShopButton()
{
    getContentPane()->addComponent(&m_shopEnter);
}

void GameView::hideShopButton()
{
    getContentPane()->removeComponent(&m_shopEnter);
}

void GameView::showShop()
{
    // Checking for it
    if(getContentPane()->getComponent(m_shop.getShopPan()) == nullptr)
        getContentPane()->addComponent(m_shop.getShopPan());
}

void GameView::hideShop()
{
    getContentPane()->removeComponent(m_shop.getShopPan());
}

void GameView::showOverlay(std::string toPress, std::string randomMessage)
{
    //m_overlayRandomMessage.setTexte(randomMessage);
    // Checking for it
    if (getContentPane()->getComponent(&m_overlay) == nullptr)
    {
        m_overlayToPress.setTexte(toPress);
        getContentPane()->addComponent(&m_overlay);
    }
}

void GameView::hideOverlay()
{
    getContentPane()->removeComponent(&m_overlay);
}

ShopItem * GameView::getShopItem(unsigned int index)
{
    return m_shop.getItem(index);
}

void GameView::EnableSound()
{
    getContentPane()->removeComponent(&m_soundOff);
    getContentPane()->addComponent(&m_soundOn);
}

void GameView::DisableSound()
{
    getContentPane()->removeComponent(&m_soundOn);
    getContentPane()->addComponent(&m_soundOff);
}