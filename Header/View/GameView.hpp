#ifndef __GAME_VIEW_HPP
#define __GAME_VIEW_HPP

#include "Interface/BasicInterface.hpp"

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


    // SHOP
    void showShopButton();
    void hideShopButton();
    void showShop();
    void hideShop();

private:

    NLabel m_money;
    NLabel m_hitPoint;
    NLabel m_nextRoundIn;
    NLabel m_difficulty;
    NLabel m_BonusPhase;

    NButton m_exitButton;
    NButton m_optButton;

    NPanel m_shop;
    NButton m_shopExit;
    NButton m_shopEnter;
};

#endif // __GAME_VIEW_HPP