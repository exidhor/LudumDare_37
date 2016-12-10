/**
 * \brief Handle all texture
 * \file FontManager.hpp
 * \author Aredhele
 * \version 0.1
 * \date 12/12/2015
 * \class FontManager.hpp
 */

#ifndef DEF_FONT_MANAGER_HPP
#define DEF_FONT_MANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "Interface/Manager.hpp"

class FontManager : public Manager
{
    private:
        std::map <std::string, sf::Font *> m_fontMap;

    public:
        // Constructor
        FontManager(bool debug);

        // Destructor
        ~FontManager();

        // Methods
        void addFont(std::string key, std::string path);

        // Getter
        sf::Font * getFont(std::string key);
};

#endif // DEF_FONT_MANAGER_HPP
