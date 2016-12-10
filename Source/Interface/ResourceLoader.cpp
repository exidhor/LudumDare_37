/*!
 * \file resourceLoader.cpp
 * \brief Load all resources in a thread
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#include "Interface/ResourceLoader.hpp"

/*!
 * \brief Constructor
 * \param debug the debug mode
 */
ResourceLoader::ResourceLoader(bool debug) : m_managerGroup(), 
m_thread(&ResourceLoader::load, this) {
	m_debug = debug;

	m_managerGroup.ptr_musicManager = new MusicManager(m_debug);
	m_managerGroup.ptr_textureManager = new TextureManager(m_debug);
	m_managerGroup.ptr_targetManager = new TargetManager(m_debug);
	m_managerGroup.ptr_optionManager = new OptionManager(m_debug);
	m_managerGroup.ptr_fontManager = new FontManager(m_debug);

	m_managerGroup.ptr_musicManager->setState(false);
	m_managerGroup.ptr_textureManager->setState(false);
	m_managerGroup.ptr_targetManager->setState(false);
	m_managerGroup.ptr_optionManager->setState(false);
	m_managerGroup.ptr_fontManager->setState(false);
}

/*!
 * \brief Destructor
 */
ResourceLoader::~ResourceLoader() {
	// None
}

/*!
 * \brief Load all ressource in a thread
 * \brief to not lock the main thread
 */
void ResourceLoader::load() {

	// Aliases
	FontManager& a_fm = *m_managerGroup.ptr_fontManager;
	MusicManager& a_mm = *m_managerGroup.ptr_musicManager;
	TextureManager& a_tm = *m_managerGroup.ptr_textureManager;
	TargetManager& a_tarm = *m_managerGroup.ptr_targetManager;
	OptionManager& a_optm = *m_managerGroup.ptr_optionManager;

	// Path
	const std::string path = "../res/";

	a_tm.addTexture("cursor", path + "textures/Cursor.png");
	a_tm.addTexture("textField", path + "textures/TextField.png");
	a_tm.addTexture("pseudoButton1", path + "textures/ValidatePseudo_1.png");
	a_tm.addTexture("pseudoButton2", path + "textures/ValidatePseudo_2.png");

	a_tm.addTexture("startMenu1", path + "textures/StartMenu_1.png");
	a_tm.addTexture("startMenu2", path + "textures/StartMenu_2.png");
	a_tm.addTexture("exitMenu1", path + "textures/ExitMenu_1.png");
	a_tm.addTexture("exitMenu2", path + "textures/ExitMenu_2.png");

	a_tm.addTexture("wallUp", path + "textures/UpWall.png");
	a_tm.addTexture("wallDown", path + "textures/DownWall.png");
	a_tm.addTexture("wallLeft", path + "textures/LeftWall.png");
	a_tm.addTexture("wallRight", path + "textures/RightWall.png");
	a_tm.addTexture("wallUpLeft", path + "textures/UpLeftWall.png");
	a_tm.addTexture("wallUpRight", path + "textures/UpRightWall.png");
	a_tm.addTexture("wallDownLeft", path + "textures/DownLeftWall.png");
	a_tm.addTexture("wallDownRight", path + "textures/DownRightWall.png");

	a_tm.addTexture("downRightShadow", path + "textures/DownRightShadowWall.png");
	a_tm.addTexture("downLeftShadow", path + "textures/DownLeftShadowWall.png");
	a_tm.addTexture("upRightShadow", path + "textures/UpRightShadowWall.png");
	a_tm.addTexture("upLeftShadow", path + "textures/UpLeftShadowWall.png");
	a_tm.addTexture("upShadow", path + "textures/UpShadowWall.png");
	a_tm.addTexture("downShadow", path + "textures/DownShadowWall.png");
	a_tm.addTexture("leftShadow", path + "textures/LeftShadowWall.png");
	a_tm.addTexture("rightShadow", path + "textures/RightShadowWall.png");

	a_tm.addTexture("blackWall", path + "textures/BlackWall.png");
	a_tm.addTexture("ground", path + "textures/Ground.png");

	a_tm.addTexture("TilePlayer", path + "tiles/TilePlayer.png");
	a_tm.addTexture("WeaponsUI", path + "textures/WeaponsUI.png");
	a_tm.addTexture("hitPoint", path + "textures/hitPoint.png");

	a_tm.addTexture("Bow", path + "textures/Bow.png");
	a_tm.addTexture("Arrow", path + "textures/Arrow.png");

	a_fm.addFont("regFont", path + "fonts/Vanthian_Ragnarok.ttf");

	a_fm.setState(true);
	a_mm.setState(true);
	a_tm.setState(true);
	a_tarm.setState(true);
	a_optm.setState(true);

	if(m_debug) {
		std::cout << "- Texture Manager successfully loaded" << std::endl;
		std::cout << "- Target Manager successfully loaded" << std::endl;
		std::cout << "- Option Manager successfully loaded" << std::endl;
		std::cout << "- Font Manager successfully loaded" << std::endl;
	}
}

/*!
 * \brief Launch the loading thread
 */
void ResourceLoader::start() {
	m_thread.launch();
	sf::sleep(sf::seconds(0.1));
}

/*!
 * \brief Stop the loading thead
 * \deprecated Please do not use this function
 */
void ResourceLoader::stop() {
	m_thread.terminate();
}

/*!
 * \brief Check if the load is up
 * \return True if all resources are loaded
 */
bool ResourceLoader::getLoadState() {
	return (
	m_managerGroup.ptr_musicManager->getState() &&
	m_managerGroup.ptr_textureManager->getState() &&
	m_managerGroup.ptr_targetManager->getState() &&
	m_managerGroup.ptr_optionManager->getState() &&
	m_managerGroup.ptr_fontManager->getState());
}

/*!
 * \brief Return all loaded resources
 * \return m_manager a pointer on all managers
 */
ManagerGroup * ResourceLoader::getManager() {
	return &m_managerGroup;
}