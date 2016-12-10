/**
 * \file Interfaces.cpp
 * \brief Include all utilities for interface
 * \author Aredhele
 * \version 0.1
 * \date 2016-02-03
 */

#include "Interface/Interface.hpp"

/**
 * \brief Constructor
 */
Interface::Interface() :
m_clock(),
m_window(),
m_resourceLoad(DEBUG)
{
	// None
}

/**
 * \brief Destructor
 */
Interface::~Interface() {
	// None
}

/**
 * \brief Load all resources into managers
 */
void Interface::loadResources() {
	m_resourceLoad.start();
}

/**
 * \brief Wait the full loading of resources
 */
void Interface::waitResources() {
	while(!m_resourceLoad.getLoadState()) 
		sf::sleep(sf::milliseconds(WAIT_TIME));
}

/**
 * \brief Create the Window
 */
void Interface::createWindow() {
	m_window = new NWindow();
}

/**
 * \brief Bind a NWindow
 */
void Interface::bindWindow(NWindow * w) {
	m_window = w;
}

/**
 * \brief Update managers
 */
void Interface::update() {
	// chargeurRessource.getManager()->ptr_musicManager->update();
}

/**
 * \brief Reset le temps de la boucle
 */
void Interface::restartClock() {
	m_clock.restart().asMilliseconds();
}

/**
 * \brief Return resources
 */
ManagerGroup * Interface::getResources() {
	return m_resourceLoad.getManager();
}

/**
 * \brief Return the window
 */
NWindow * Interface::getWindow() {
	return m_window;
}

double Interface::getTimeSeconds() {
	return m_clock.getElapsedTime().asSeconds();
}

double Interface::getTimeMilliseconds() {
	return m_clock.getElapsedTime().asMilliseconds();
}