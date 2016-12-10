/*!
 * \file NTextField.cpp
 * \brief A text field can contain at most one line
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#include "Interface/NTextField.hpp"
#include <iostream>
/*!
 * \brief Constructor
 * \param id The id of the object
 */
NTextField::NTextField() :
	VisualObject(),
	m_cursorPosition(0, 0) 
{
	m_flashingDelay = 1.0;
	m_isFlashed = true;
	m_maxSize = 20;
	m_fontSize = 10;
}

/*!
 * \brief Destructor
 */
NTextField::~NTextField() {
	// None
}

/*!
 * \brief Constructor
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture_1 The texture of the main sprite
 * \param texture_2 The texture of the second sprite
 * \param ptr_font A pointer on the font
 * \param fontSize The size of the displayed text
 * \param flashingDelay The time between two flahses
 */
void NTextField::create(std::string id, int x, int y, 
	sf::Texture * texture_1, sf::Texture * texture_2,
	sf::Font * ptr_font, int fontSize, 
	float flashingDelay, std::string const& text,
	int maxSize, sf::Color color) {

	(void)flashingDelay;
	(void)text;

	m_flashingDelay = flashingDelay;

	// Call super method
	init(id, x, y, texture_1);

	m_cursorPosition.x = x + 20;
	m_cursorPosition.y = y + 10;

	m_secondSprite.setTexture(*texture_2);
	m_secondSprite.setPosition(m_cursorPosition);

	sf::Vector2f textPosition(
		m_cursorPosition.x + 3,
		m_cursorPosition.y + 2);

	// Init sf::texte
	m_text.setFont(*ptr_font);


	m_text.setString(text);
	if(text.size() >= 1)
	{
		for(unsigned i = 0; i < text.size(); ++i)
			m_charList.push_back(text[i]);

		float coefFont = 1.85;
		m_cursorPosition.x += 2 * text.size() * (m_fontSize / coefFont);
		m_secondSprite.setPosition(m_cursorPosition);
	}

	m_text.setCharacterSize(fontSize);
	m_text.setPosition(textPosition);
	m_text.setFillColor(color);
	m_maxSize = maxSize;
	m_fontSize = fontSize;
}

/*!
 * \brief Draw the current state of the button
 * \param window The pointer on the window
 */
void NTextField::draw(sf::RenderWindow * window) {

	if(m_hidden || !m_isEnable) return;

	window->draw(m_mainSprite);
	window->draw(m_text);

	if(m_isActive) {
		if(m_isFlashed) window->draw(m_secondSprite);
	}
}

/*!
 * \param texture_1 The pointer on the main texture
 * \param texture_2 The pointer on the second texture
 */
void NTextField::setSprite(sf::Texture * texture_1,
sf::Texture * texture_2) {
	m_mainSprite.setTexture(*texture_1);
	m_secondSprite.setTexture(*texture_2);
}

/*!
 * \param x The x position of the object
 * \param y The y position of the object
 */
void NTextField::setPosition(float x, float y) {
	m_position.x = x;
	m_position.y = y;
	m_mainSprite.setPosition(m_position);
	m_secondSprite.setPosition(m_position);
}


/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NTextField::eventMousePressed(sf::Event * e) {

	std::string id = "NULL";
	if(!m_isEnable) return id;

	sf::FloatRect mousePosition(e->mouseButton.x, 
	e->mouseButton.y, 1, 1);

	if(m_mainSprite.getGlobalBounds().
	intersects(mousePosition)) {

		id = m_id;
		m_isActive = true;
	}
	else {
		m_isActive = false;
	}

	return id;
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NTextField::eventMouseMoved(sf::Event * e) {
	(void)e;
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void NTextField::eventTextEntered(sf::Event * e) {
	
	float coefFont = 1.85;

	if(!m_isEnable || !m_isActive) return;
	if(m_text.getString().getSize() < (unsigned)m_maxSize) {

		if(e->text.unicode == 8)  { // BackSpace
			if(m_charList.size() > 0) {
				m_charList.pop_back();
				m_cursorPosition.x -= m_fontSize / coefFont;
				m_secondSprite.setPosition(m_cursorPosition);
			}
		} else if(e->text.unicode == 32) { // Space
			m_charList.push_back(' ');
			//m_cursorPosition.x += m_fontSize / 1.5;
			m_cursorPosition.x += m_fontSize / coefFont;
			m_secondSprite.setPosition(m_cursorPosition);
		} else if(e->text.unicode == 13) { // Carriage Return
			m_isActive = false;
		}
		 else {
			m_charList.push_back(
				static_cast < char >(e->text.unicode));
			if(e->text.unicode > 96 || e->text.unicode < 123) {
				m_cursorPosition.x += m_fontSize / coefFont;
				//m_cursorPosition.x += m_fontSize;
			} else if(e->text.unicode > 64 || e->text.unicode < 91) {
				//m_cursorPosition.x += m_fontSize * 2;
				m_cursorPosition.x += m_fontSize / coefFont;
			}
			
			m_secondSprite.setPosition(m_cursorPosition);
		}

		// Updating string
		m_text.setString(m_charList);
	} 
	else {
		if(m_text.getString().getSize() > 0) {
			if(e->text.unicode == 8)  { // BackSpace
				if(m_charList.size() > 0) {
					m_charList.pop_back();
					m_cursorPosition.x -= m_fontSize / coefFont;
					m_secondSprite.setPosition(m_cursorPosition);

					// Updating string
					m_text.setString(m_charList);
				}
			}
		}
		return;
	}
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void NTextField::update(double frameTime) {

	if(m_isActive) m_timeElapsed += frameTime;

	if(m_timeElapsed > m_flashingDelay) {
		m_isFlashed = !m_isFlashed;
		m_timeElapsed = 0;
	}
}

/*! 
 * \brief Return the text
 * \return m_charList The string of the textfield
 */
std::string const& NTextField::getString() {
	return m_charList;
}