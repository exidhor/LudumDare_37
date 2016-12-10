/*!
 * \file ManagerGroup.hpp
 * \brief Store all managers
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#ifndef DEF_MANAGER_GROUP_HPP
#define DEF_MANAGER_GROUP_HPP

#include "Interface/MusicManager.hpp"
#include "Interface/OptionManager.hpp"
#include "Interface/TargetManager.hpp"
#include "Interface/TextureManager.hpp"
#include "Interface/FontManager.hpp"

class ManagerGroup
{
	public:
		// Constructor
		ManagerGroup();

		// Destructor
		~ManagerGroup();

		// Token
		MusicManager * ptr_musicManager;
		TextureManager * ptr_textureManager;
		TargetManager * ptr_targetManager;
		OptionManager * ptr_optionManager;
		FontManager * ptr_fontManager;
};

#endif // DEF_MANAGER_GROUP_HPP