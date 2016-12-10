#include "View/GameView.hpp"
#include "Memory/Container.hpp"

/* explicit */ GameView::GameView(bool debug, InputHandler * inputHandler)
: BasicInterface(debug, inputHandler)
{

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
