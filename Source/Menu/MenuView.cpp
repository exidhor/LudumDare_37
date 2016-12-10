#include "Menu/MenuView.hpp"

MenuView::MenuView(bool debug, ManagerGroup * ptr_managerGroup,
	InputHandler * inputHandler) : 
	BasicInterface(debug, ptr_managerGroup, inputHandler) 
{
	m_startButton.create("startButton", 500, 200, 
		ptr_managerGroup->ptr_textureManager->getTexture("startMenu1"),
		ptr_managerGroup->ptr_textureManager->getTexture("startMenu2"));

	m_exitButton.create("exitButton", 500, 400, 
		ptr_managerGroup->ptr_textureManager->getTexture("exitMenu1"),
		ptr_managerGroup->ptr_textureManager->getTexture("exitMenu2"));

	getContentPane()->addComponent(&m_startButton);
	getContentPane()->addComponent(&m_exitButton);
}

MenuView::~MenuView() {
	// None
}

void MenuView::update(NEvent * e, double frameTime) {
	basicInput(e, frameTime);
}

void MenuView::draw(NWindow * w) {
	basicDraw(w);
}