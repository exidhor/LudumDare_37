#include "View/MenuView.hpp"
#include "Memory/Container.hpp"

/* explicit */ MenuView::MenuView(bool debug, InputHandler * inputHandler)
: BasicInterface(debug, inputHandler)
{
    Container <sf::Texture> * p_Tcontainer = Container<sf::Texture>::Instance();

    m_background.create("MENU", 0, 0,
                        Container<sf::Texture>::Instance()->GetResource("MENU_BG"));

    m_startButton.create("START_BUTTON", 560, 270,
         Container<sf::Texture>::Instance()->GetResource("PLAY_R"),
         Container<sf::Texture>::Instance()->GetResource("PLAY_P"));

    m_exitButton.create("EXIT_BUTTON", 560, 420,
        Container<sf::Texture>::Instance()->GetResource("QUIT_R"),
        Container<sf::Texture>::Instance()->GetResource("QUIT_P"));

    getContentPane()->addComponent(&m_background);
    getContentPane()->addComponent(&m_startButton);
    getContentPane()->addComponent(&m_exitButton);
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