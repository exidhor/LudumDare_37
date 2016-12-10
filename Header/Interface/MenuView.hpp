#ifndef DEF_MENU_VIEW_HPP
#define DEF_MENU_VIEW_HPP

#include "Interface/BasicInterface.hpp"

class MenuView : public BasicInterface
{
public:
	MenuView(
		bool debug, 
		ManagerGroup * ptr_managerGroup,
		InputHandler * inputHandler);

	~MenuView();

	virtual void update(NEvent * e, double frameTime);
	virtual void draw(NWindow * w);

private:

	NButton m_startButton;
	NButton m_exitButton;
};

#endif // DEF_MENU_VIEW_HPP