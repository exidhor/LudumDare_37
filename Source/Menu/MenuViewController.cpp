#include "Menu/MenuViewController.hpp"

MenuViewController::MenuViewController() {
	// None
}

MenuViewController::~MenuViewController() {
	// None
}

void MenuViewController::init(MenuView * view, 
	InputHandler * controller)
{
	m_next = false;
	m_exit = false;
	m_view = view;
	m_controller = controller;
}

bool MenuViewController::next() {

	if(m_controller->getComponentId() == "startButton") {
		m_next = true;
	}

	return m_next;
}

bool MenuViewController::exit() {

	if(m_controller->getComponentId() == "exitButton") {
		m_exit = true;
	}

	return m_exit;
}