/*!
 * \file NPanel.hpp
 * \brief Panel container
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_NPANEL_HPP
#define DEF_NPANEL_HPP

#include <vector>

#include "Interface/VisualObject.hpp"

class NPanel : public VisualObject
{
	private:
		std::vector < VisualObject * > m_vObjectList;
		bool isTextured;

	public:
		// Constructor
		NPanel();

		// Destructor
		virtual ~NPanel();

		// Methods
		void create(std::string id, int x, int y, 
		sf::Texture * texture = NULL);
		
		virtual void draw(sf::RenderWindow * window);
		virtual std::string eventMousePressed(sf::Event * e);
		virtual std::string eventMouseMoved(sf::Event * e);
		virtual void eventTextEntered(sf::Event * e);
		virtual void update(double frameTime);

		void addComponent(VisualObject * component);
		void removeLastComponent();
	    void removeComponent(VisualObject * component);
		int getNumberOfComponents();
		VisualObject * getLastComponent();

    VisualObject *getComponent(VisualObject *component);
};

#endif // DEF_NPANEL_HPP