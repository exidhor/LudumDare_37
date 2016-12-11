//
// Created by Kraghan on 11/12/2016.
//

#include "View/GameOverView.hpp"
#include "Memory/Container.hpp"

GameOverView::GameOverView(bool debug, InputHandler *inputHandler)
        : BasicInterface(debug, inputHandler)
{
    m_replay.create("REPLAY_BUTTON", 500, 400,
                    Container<sf::Texture>::Instance()->GetResource("QUIT_R"),
                    Container<sf::Texture>::Instance()->GetResource("QUIT_P"));

    m_mainMenu.create("BACK_TO_MAIN_MENU", 500, 500,
                            Container<sf::Texture>::Instance()->GetResource("QUIT_R"),
                            Container<sf::Texture>::Instance()->GetResource("QUIT_P"));

    m_score.create("SCORE",400,200,25,
                            Container<sf::Font>::Instance()->GetResource("FONT"),
                   "Score : ", sf::Color::Black );

    getContentPane()->addComponent(&m_replay);
    getContentPane()->addComponent(&m_mainMenu);
    getContentPane()->addComponent(&m_score);
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
