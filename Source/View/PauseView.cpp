#include "View/PauseView.hpp"
#include "Memory/Container.hpp"

/* explicit */ PauseView::PauseView(bool debug, InputHandler * inputHandler)
: BasicInterface(debug, inputHandler)
{
    m_resume.create("RESUME_BUTTON", 500, 400,
                        Container<sf::Texture>::Instance()->GetResource("QUIT_R"),
                        Container<sf::Texture>::Instance()->GetResource("QUIT_P"));

    getContentPane()->addComponent(&m_resume);
}

/* virtual */ PauseView::~PauseView()
{
    // None
}

/* virtual */ void PauseView::update(double elapsed)
{
    basicUpdate(elapsed);
}

/* virtual */ void PauseView::processInput(sf::Event & e)
{
    basicInput(e);
}

/* virtual */ void PauseView::draw(sf::RenderWindow * w)
{
    basicDraw(w);
}