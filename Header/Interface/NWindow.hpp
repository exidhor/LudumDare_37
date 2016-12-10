/**
 * \file NWindow.hpp
 * \brief Encapsulate sf::RenderWindow
 * \author Aredhele
 * \version 0.1
 * \date 2016-02-02
 */

#ifndef DEF_NWINDOW_HPP
#define DEF_NWINDOW_HPP

#include <SFML/Graphics.hpp>

#include "Interface/NEvent.hpp"
#include "Interface/Constant.hpp"

class NWindow : public sf::RenderWindow
{
	public:
		NWindow();
		~NWindow();

		// Méthodes
		bool isOpen();
		void close();
		void clear();
		void display();
		bool pollEvent(NEvent &e);

	private:
		// None
};


#endif // DEF_NWINDOW_HPP