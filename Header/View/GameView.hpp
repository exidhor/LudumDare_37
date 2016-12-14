#ifndef __GAME_VIEW_HPP
#define __GAME_VIEW_HPP

#include "Interface/BasicInterface.hpp"
#include "Shop.hpp"

class GameView : public BasicInterface
{
public:

    /// \brief Constructor
    /// \param debug Debug value
    /// \param inputHandler The controller
    explicit GameView(bool debug, InputHandler * inputHandler);

    /// \brief Destructor
    virtual ~GameView();

    /// \brief Update the menu
    /// \param elapsed The elapsed time
    virtual void update(double elapsed);

    /// \param e The event
    /// \param frameTime
    virtual void processInput(sf::Event & e);

    /// \param w The window
    virtual void draw(sf::RenderWindow * w);

    // TODO
    void setHitPoint(int hitPoint);

    // TODO
    void setMoney(unsigned long long money);

    void setNextRoundIn(double nextRoundIn);

    void hideNextRoundIn();
    // TODO
    void setDifficulty(unsigned int diff);

    void showBonusPhase();
    void hideBonusPhase();

    void showOverlay(std::string toPress, std::string randomMessage);
    void hideOverlay();

    // SHOP
    void showShopButton();
    void hideShopButton();
    void showShop();
    void hideShop();

    ShopItem *getShopItem(unsigned int index);

    void EnableSound();
    void DisableSound();

private:

    NLabel m_money;
    NLabel m_hitPoint;
    NLabel m_nextRoundIn;
    NLabel m_difficulty;
    NLabel m_BonusPhase;

    NButton m_soundOn;
    NButton m_soundOff;
    NButton m_shopEnter;
    NButton m_skip;

    // Shop
    Shop m_shop;

    NPanel m_overlay;
    NLabel m_overlayToPress;
    NLabel m_overlayRandomMessage;
};

#endif // __GAME_VIEW_HPP