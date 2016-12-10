#include "Menu/MenuView.hpp"

/* explicit */ MenuView::MenuView(bool debug, InputHandler * inputHandler)
: BasicInterface(debug, inputHandler)
{
	// None
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