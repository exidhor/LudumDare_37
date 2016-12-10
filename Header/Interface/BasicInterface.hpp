/*!
 * \file BasicInterface.hpp
 * \brief Super class for Interfaces
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_BASIC_INTERFACE_HPP
#define DEF_BASIC_INTERFACE_HPP

#include "Interface/NPanel.hpp"
#include "Interface/NLabel.hpp"
#include "Interface/NEvent.hpp"
#include "Interface/NButton.hpp"
#include "Interface/NWindow.hpp"
#include "Interface/Updatable.hpp"
#include "Interface/NTextField.hpp"
#include "Interface/ManagerGroup.hpp"
#include "Interface/InputHandler.hpp"
#include "Interface/AnimatableObject.hpp"

class BasicInterface : public Updatable
{
	private:
		NPanel m_contentPane;
		
		std::vector < VisualObject * > m_Interfaces;

		// Methods
		void updateInterfaces(double frameTime);

	protected:
		bool m_debug;
		bool m_optionActive;
		InputHandler * m_inputHandler;
		ManagerGroup * m_ptr_managerGroup;
		
	public:
		// Constructor
		BasicInterface(bool debug, ManagerGroup * ptr_managerGroup,
			InputHandler * inputHandler);

		// Destructor
		~BasicInterface();

		// Controllers Methods
		// Game logic
		virtual void draw(NWindow * window) = 0;
		void basicDraw(NWindow * window);
		void basicInput(NEvent * evenement, double frameTime);

		// Getters
		NPanel * getContentPane();

		// Setters
		void setContentPane(NPanel * pane);
};

#endif // DEF_BASIC_INTERFACE_HPP