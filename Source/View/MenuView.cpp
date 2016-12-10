#include "View/MenuView.hpp"
#include "Memory/Container.hpp"

/* explicit */ MenuView::MenuView(bool debug, InputHandler * inputHandler)
: BasicInterface(debug, inputHandler)
{
    Container <sf::Texture> * p_Tcontainer = Container<sf::Texture>::Instance();

    m_startButton.create("START_BUTTON", 500, 200,
         Container<sf::Texture>::Instance()->GetResource("PLAY_R"),
         Container<sf::Texture>::Instance()->GetResource("PLAY_P"));

    m_exitButton.create("EXIT_BUTTON", 500, 400,
        Container<sf::Texture>::Instance()->GetResource("QUIT_R"),
        Container<sf::Texture>::Instance()->GetResource("QUIT_P"));

    m_soundButton.create("SOUND_BUTTON", 900, 190,
        Container<sf::Texture>::Instance()->GetResource("CSOUND"),
        Container<sf::Texture>::Instance()->GetResource("CSOUND"));

    getContentPane()->addComponent(&m_startButton);
    getContentPane()->addComponent(&m_exitButton);
    getContentPane()->addComponent(&m_soundButton);
}

/* virtual */ MenuView::~MenuView()
{
	// None
}

/* virtual */ void MenuView::update(double elapsed)
{
    basicUpdate(elapsed);
}

/* virtual */ void MenuView::processInput(sf::Event & e)
{
	basicInput(e);
}

/* virtual */ void MenuView::draw(sf::RenderWindow * w)
{
    basicDraw(w);
}