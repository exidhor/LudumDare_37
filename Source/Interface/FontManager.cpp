/**
 * \brief Handle all fonts
 * \file FontManager.hpp
 * \author Aredhele
 * \version 0.1
 * \date 12/12/2015
 * \class FontManager.hpp
 */

#include "Interface/FontManager.hpp"

/**
 *  \brief Constructor
 */
FontManager::FontManager(bool debug) : Manager() {
	m_debug = debug;
    m_state = false;
}

/**
 * \brief Destructor
 */
FontManager::~FontManager() {
    // None
}

/**
 * \brief Add a font to the specified map by the key
 * \param key the key of the font
 */
void FontManager::addFont(std::string key, std::string path) {

    sf::Font * font = new sf::Font();
    if(!font->loadFromFile(path)) {
    	if(m_debug) {
        	std::cerr << "Unable to open the file" << std::endl;
    	}
    }

    m_fontMap.insert(std::pair <std::string, sf::Font *> (key, font));
}

/**
 * \brief return the specified font
 * \param key the key to access the map
 */
sf::Font * FontManager::getFont(std::string key) {
    return m_fontMap[key];
}