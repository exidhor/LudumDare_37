#ifndef DEF_MENU_VIEW_CONTROLLER_HPP
#define DEF_MENU_VIEW_CONTROLLER_HPP

#include <iostream>

#include "Interface/MenuView.hpp"
#include "Interface/InputHandler.hpp"

class MenuViewController
{
public:
	MenuViewController();
	~MenuViewController();

	void init(
		MenuView * view, 
		InputHandler * controller);

	bool next();
	bool exit();

private:

	bool m_next;
	bool m_exit;

	MenuView * m_view;
	InputHandler * m_controller;
};

#endif // DEF_MENU_VIEW_CONTROLLER_HPP