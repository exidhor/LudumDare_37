/*!
 * \file NLabel.hpp
 * \brief Handle a label
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#ifndef DEF_NLABEL_HPP
#define DEF_NLABEL_HPP

#include "Interface/VisualObject.hpp"

class NLabel : public VisualObject 
{
	private:
		sf::Font * m_ptr_font;
		sf::Text m_text;

	public:
		// Constructor
		NLabel();

		// Destructor
		~NLabel();

		// Methods
		void create(std::string id, int x, int y, 
		int size, sf::Font * ptr_font,
		std::string text, sf::Color color);

		virtual void draw(sf::RenderWindow * window);
		virtual std::string eventMousePressed(sf::Event * e);
		virtual std::string eventMouseMoved(sf::Event * e);
		virtual void eventTextEntered(sf::Event * e);
		virtual void update(double frameTime);
		virtual void setPosition(float x, float y);

		void setTexte(std::wstring const& texte);
		void setTexte(std::string const& texte);
};

#endif // DEF_NLABEL_HPP