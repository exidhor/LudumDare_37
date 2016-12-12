//
// Created by Kraghan on 11/12/2016.
//

#include "View/GameOverView.hpp"

GameOverView::GameOverView(bool debug, InputHandler *inputHandler)
        : BasicInterface(debug, inputHandler)
{
    m_background.create("GAME_OVER_PANE",0,0,Container<sf::Texture>::Instance()->GetResource("GAMEOVER"));

    m_replay.create("REPLAY_BUTTON", 500, 400,
                    Container<sf::Texture>::Instance()->GetResource("REPLAY_R"),
                    Container<sf::Texture>::Instance()->GetResource("REPLAY_P"));

    m_mainMenu.create("BACK_TO_MAIN_MENU", 500, 500,
                            Container<sf::Texture>::Instance()->GetResource("MAIN_MENU_R"),
                            Container<sf::Texture>::Instance()->GetResource("MAIN_MENU_P"));

    getContentPane()->addComponent(&m_background);
    getContentPane()->addComponent(&m_replay);
    getContentPane()->addComponent(&m_mainMenu);
}

GameOverView::~GameOverView()
{

}

void GameOverView::update(double elapsed)
{

}

void GameOverView::processInput(sf::Event &e)
{
    basicInput(e);
}

void GameOverView::draw(sf::RenderWindow *w)
{
    basicDraw(w);
}
