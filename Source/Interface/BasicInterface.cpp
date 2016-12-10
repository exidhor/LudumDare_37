/*!
 * \file BasicInterface.cpp
 * \brief Super class for Interfaces
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "Interface/BasicInterface.hpp"

/*!
 * \brief Constructor
 * \param ptr_managerGroup
 */
BasicInterface::BasicInterface(bool debug, 
	ManagerGroup * ptr_managerGroup,
	InputHandler * inputHandler) : Updatable(),
	m_contentPane()
{
	m_debug = debug;
	m_optionActive = false;
	m_ptr_managerGroup = ptr_managerGroup;
	m_inputHandler = inputHandler;

	// Setting up aliases
	TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;

	// Creating m_contentPane
	m_contentPane.create("mainPanel", 0, 0, 
		a_tm.getTexture("monstrePanneau"));

	m_Interfaces.push_back(&m_contentPane);
}

/*!
 * \brief Destructor
 */
BasicInterface::~BasicInterface() {
	// None
}

/*!
 * \brief Draw all object on the window
 * \param window The surface to draw
 * \param visualObjectList The list of object to draw
 */
void BasicInterface::basicDraw(sf::RenderWindow *window) {

	// Polymorphisme !
	for(unsigned int i = 0; i < m_Interfaces.size(); i++)
		m_Interfaces[i]->draw(window);
}

/*!
 * \brief Update all component
 * \param frameTime Time elapsed since last frame
 */
void BasicInterface::updateInterfaces(double frameTime) {

	// Polymorphisme !
	for(unsigned int i = 0; i < m_Interfaces.size(); i++) {
		m_Interfaces[i]->update(frameTime);
	}
}

/*!
 * \brief Handle inputs of the basics Interfaces
 * \param e The current event to handle
 * \param frameTime TimeElapsed since last iteration
 */
void BasicInterface::basicInput(NEvent * evenement, double frameTime) {

	// Updating components
	updateInterfaces(frameTime);

	// Checking for contentPane Event
	m_inputHandler->handleInput(evenement, &m_contentPane, true);
}

/*!
 * \brief Allow the acces on the main panel
 * \return m_contentPane The reference on the main panel
 */
NPanel * BasicInterface::getContentPane() {
	return &m_contentPane;
}

/*!
 * \brief Replace the current main panel
 * \param pane The pointeur on the panel
 * \return None
 */
void BasicInterface::setContentPane(NPanel * pane) {
	m_contentPane = *pane;
}