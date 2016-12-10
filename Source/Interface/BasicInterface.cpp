/*!
 * \file BasicInterface.cpp
 * \brief Super class for Interfaces
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "Interface/BasicInterface.hpp"

BasicInterface::BasicInterface(bool debug, InputHandler * inputHandler)
: m_contentPane()
{
	m_debug = debug;
	m_optionActive = false;
	m_inputHandler = inputHandler;
	m_Interfaces.push_back(&m_contentPane);
}

BasicInterface::~BasicInterface()
{
	// None
}

void BasicInterface::basicDraw(sf::RenderWindow * window)
{
	for(unsigned int i = 0; i < m_Interfaces.size(); i++)
		m_Interfaces[i]->draw(window);
}

void BasicInterface::updateInterfaces(double frameTime)
{
	for(unsigned int i = 0; i < m_Interfaces.size(); i++)
		m_Interfaces[i]->update(frameTime);
}

void BasicInterface::basicUpdate(double elapsed)
{
    updateInterfaces(elapsed);
}

void BasicInterface::basicInput(sf::Event & event)
{
	// Checking for contentPane Event
	m_inputHandler->handleInput(event, &m_contentPane, true);
}

NPanel * BasicInterface::getContentPane()
{
	return &m_contentPane;
}

void BasicInterface::setContentPane(NPanel * pane)
{
	m_contentPane = *pane;
}
