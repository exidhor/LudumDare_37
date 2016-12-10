/*!
 * \file TargetManager.cpp
 * \brief Handle target choice
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#include "Interface/TargetManager.hpp"

/*!
 * \brief Constructor
 */
TargetManager::TargetManager(bool debug) : Manager() {
	m_debug = debug;

	m_onControlleursMenu = false;
	surAccueil = false;
	surSalon = false;
}

/*!
 * \brief Destructor
 */
TargetManager::~TargetManager() {
	// None
}

/*!
 * \brief Set all targets to false
 */
void TargetManager::exit() {
	handleTarget();
}

/*!
 * \brief Set all target to false
 */
void TargetManager::handleTarget() {
	surSalon = false;
	m_onControlleursMenu = false;
	surAccueil = false;
}

/*!
 * \return true if all target are on false
 */
bool TargetManager::isExit() {
	return (m_onControlleursMenu || 
			surSalon  ||
			surAccueil);
}

/*!
 * \return m_onLoginMenu target state
 */
bool TargetManager::isSurSalon() {
	return surSalon;
}

/*!
 * \return m_onLoginMenu target state
 */
bool TargetManager::isControlleursMenu() {
	return m_onControlleursMenu;
}

/*!
 * \return surAccueil target state
 */
bool TargetManager::isSurAccueil() {
	return surAccueil;
}

/*!
 * \return m_onLoginMenu target state
 */
void TargetManager::allerSurSalon() {
	handleTarget();
	surSalon = true;
}

/*!
 * \return m_onControlleursMenu target state
 */
void TargetManager::isOnControlleursMenu() {
	handleTarget();
	m_onControlleursMenu = true;
}

/*!
 * \brief set State of boolean target
 */
void TargetManager::allerSurAccueil() {
	handleTarget();
	surAccueil = true;
}