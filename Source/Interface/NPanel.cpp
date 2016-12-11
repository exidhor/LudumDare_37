/*!
 * \file NPanel.cpp
 * \brief Panel container
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "Interface/NPanel.hpp"
 
/*!
 * \brief Constructor
 * \return None
 */
NPanel::NPanel() :
VisualObject() {
	isTextured = false;
}

/*!
 * \brief Destructor
 */
NPanel::~NPanel() {
	// None
}

/*!
 * \brief Init methode
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture The texture of the main sprite
 */
void NPanel::create(std::string id, int x, int y, 
sf::Texture * texture) {

	if (texture != NULL)
	{
		isTextured = true;
	}
	// Call super method
	init(id, x, y, texture);
}

/*!
 * \brief Draw all object in the panel
 * \param window The pointer on window
 */
void NPanel::draw(sf::RenderWindow * window) {
	
	if(m_hidden) return;

	if (isTextured)
	{
		window->draw(m_mainSprite);
	}

	for(unsigned int i = 0; i < m_vObjectList.size(); i++)
		m_vObjectList[i]->draw(window);
}

/*!
 * \brief Add a visual object the to panel
 * \param component The pointer on the object
 */
void NPanel::addComponent(VisualObject * component) {
	m_vObjectList.push_back(component);
}

/*!
 * \brief Remove the last component
 */
void NPanel::removeLastComponent() {
	m_vObjectList.pop_back();
}

VisualObject * NPanel::getLastComponent() {
	return m_vObjectList.back();
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NPanel::eventMousePressed(sf::Event * e) {

	std::string id = "NULL";

	if(m_hidden) return id;

	for(unsigned int i = 0; i < m_vObjectList.size(); i++) {
		id = m_vObjectList[i]->eventMousePressed(e);
		if(id != "NULL")
			break;
	}

	return id;

}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NPanel::eventMouseMoved(sf::Event * e) {

	std::string id = "NULL";

	if(m_hidden) return id;

	for(unsigned int i = 0; i < m_vObjectList.size(); i++) {
		id = m_vObjectList[i]->eventMouseMoved(e);
		if(id != "NULL")
			break;
	}

	return id;
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void NPanel::eventTextEntered(sf::Event * e) {

	if(m_hidden) return;

	for(unsigned int i = 0; i < m_vObjectList.size(); i++)
		m_vObjectList[i]->eventTextEntered(e);
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void NPanel::update(double frameTime) {

	for(unsigned int i = 0; i < m_vObjectList.size(); i++) {
		m_vObjectList[i]->update(frameTime);
	}
}

/*!
* \brief Get the size of the components list in the panel
* \return size of components list
*/
int NPanel::getNumberOfComponents() {
	return m_vObjectList.size();
}

void NPanel::removeComponent(VisualObject * component)
{
	for(unsigned i = 0; i < m_vObjectList.size(); ++i)
	{
		if (component == m_vObjectList[i])
		{
			m_vObjectList.erase(m_vObjectList.begin() + i);
			break;
		}
	}
}
