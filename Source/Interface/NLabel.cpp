/*!
 * \file BasicInterface.cpp
 * \brief Super class for Interfaces
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "Interface/NLabel.hpp"

/*!
 * \brief Constructor
 * \return None
 */
NLabel::NLabel() :
VisualObject(), m_text() {
	// None
}

/*!
 * \brief Destructor
 */
NLabel::~NLabel() {
	// None
}

/*!
 * \brief Init methode
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture The texture of the main sprite
 */
void NLabel::create(std::string id, int x, int y, int size, 
sf::Font * ptr_font, std::string text, sf::Color color) {

	m_ptr_font = ptr_font;
	m_id = id;
	m_position.x = x;
	m_position.y = y;

	m_text.setFont(*ptr_font);
	m_text.setString(text);
	m_text.setCharacterSize(size);
	m_text.setPosition(m_position);
	m_text.setFillColor(color);
}

/*!
 * \brief Draw all object in the panel
 * \param window The pointer on window
 */
void NLabel::draw(sf::RenderWindow * window) {
	
	if(m_hidden) return;
	window->draw(m_text);
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NLabel::eventMousePressed(sf::Event * e) {

	(void)e;
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NLabel::eventMouseMoved(sf::Event * e) {

	(void)e;
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void NLabel::eventTextEntered(sf::Event * e) {

	(void)e;
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void NLabel::update(double frameTime) {

	(void)frameTime;
}

/**
 * \brief Change le texte du label
 * \param texte Le nouveau texte du label
 */
void NLabel::setTexte(std::wstring const& texte) {
	m_text.setString(texte);
}

/**
 * \brief Change le texte du label
 * \param texte Le nouveau texte du label
 */
void NLabel::setTexte(std::string const& texte) {
	m_text.setString(texte);
}

/*!
 * \param x The x position of the object
 * \param y The y position of the object
 */
void NLabel::setPosition(float x, float y) {
	m_position.x = x;
	m_position.y = y;
	m_text.setPosition(m_position);
}