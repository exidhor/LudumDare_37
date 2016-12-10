#ifndef __MENU_VIEW_HPP
#define __MENU_VIEW_HPP

#include "Interface/BasicInterface.hpp"

class MenuView : public BasicInterface
{
public:

    /// \brief Constructor
    /// \param debug Debug value
    /// \param inputHandler The controller
	explicit MenuView(bool debug, InputHandler * inputHandler);

    /// \brief Destructor
	virtual ~MenuView();

    /// \brief Update the menu
    /// \param elapsed The elapsed time
    virtual void update(double elapsed);

    /// \param e The event
    /// \param frameTime
	virtual void processInput(sf::Event & e);

    /// \param w The window
	virtual void draw(sf::RenderWindow * w);

private:

	NButton m_startButton; ///< Start button
	NButton m_exitButton;  ///< Exit button
};

#endif // __MENU_VIEW_HPP



