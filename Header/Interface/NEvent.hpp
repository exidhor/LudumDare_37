/**
 * \file NEvent.hpp
 * \brief Handle an event
 * \author Aredhele
 * \version 0.1
 * \date 2016-02-03
 */

#include <SFML/Graphics.hpp>

#ifndef DEF_NEVENT_HPP
#define DEF_NEVENT_HPP

class NEvent : public sf::Event
{
	public:
		// Constructor
		NEvent();

		// Destructor
		~NEvent();
};

#endif // DEF_NEVENT_HPP
    	