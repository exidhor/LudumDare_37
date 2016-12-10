/*!
 * \file TargetManager.hpp
 * \brief Handle target choice
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#ifndef DEF_TARGER_MANAGER_HPP
#define DEF_TARGER_MANAGER_HPP

#include "Interface/Manager.hpp"

class TargetManager : public Manager
{
	private:
		bool m_onControlleursMenu;
		bool surAccueil;
		bool surSalon;

		// Method
		void handleTarget();
		
	public:
		// Constructor
		TargetManager(bool debug);

		// Destructor
		~TargetManager();

		// Method
		void exit();

		// Getters
		bool isExit();
		bool isControlleursMenu();
		bool isSurAccueil();
		bool isSurSalon();

		// Setters
		void isOnControlleursMenu();
		void allerSurAccueil();
		void allerSurSalon();
};

#endif // DEF_TARGER_MANAGER_HPP