/**
 * \file Interfaces.hpp
 * \brief Include all utilities for interface
 * \author Aredhele
 * \version 0.1
 * \date 2016-02-03
 */

#ifndef DEF_INTERFACE_HPP
#define DEF_INTERFACE_HPP

#include "Interface/ResourceLoader.hpp"
#include "Interface/TargetManager.hpp"
#include "Interface/ManagerGroup.hpp"
#include "Interface/MusicManager.hpp"

#include "Interface/NWindow.hpp"
#include "Interface/NEvent.hpp"

class Interface
{
	public:
		Interface();
		~Interface();

		void createWindow();
		void loadResources();
		void waitResources();
		void update();
		void restartClock();
		void bindWindow(NWindow * w);
		
		NWindow * getWindow();
		double getTimeSeconds();
		double getTimeMilliseconds();
		ManagerGroup * getResources();
		
	private:
		sf::Clock m_clock;
		NWindow * m_window;
		ResourceLoader m_resourceLoad;
};

#endif // DEF_INTERFACE_HPP