/**
 * \file NWindow.cpp
 * \brief Encapsulate sf::RenderWindow
 * \author Aredhele
 * \version 0.1
 * \date 2016-02-02
 */

#include "Interface/NWindow.hpp"

/**
 * \brief Constructor
 * \return None
 */
NWindow::NWindow() : sf::RenderWindow(
	sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
    WINDOW_NAME, sf::Style::Titlebar | sf::Style::Close)
{
	// Window framerate - Default : 120 fps
	 sf::RenderWindow::setFramerateLimit(WINDOW_FPS);
}

/**
 * \brief Destructor
 * \return None
 */
NWindow::~NWindow() {
	// Vide
}

/**
 * \brief Return the state of the window
 * \return True if the window is Open
 */
bool NWindow::isOpen() {
	return  sf::RenderWindow::isOpen();
}

/**
 * \brief Close the Window
 */
void NWindow::close() {
	 sf::RenderWindow::close();
}

/**
 * \brief Clear the windows
 */
void NWindow::clear() {
	 sf::RenderWindow::clear();
}

/**
 * \brief Display the content
 */
void NWindow::display() {
	 sf::RenderWindow::display();
}

/**
 * \brief the last event
 */
bool NWindow::pollEvent(NEvent &e) {
	return sf::RenderWindow::pollEvent(e);
}