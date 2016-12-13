#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Memory/Container.hpp"
#include "Memory/ResourceLoader.hpp"

#define INTERFACE_PATH ("Images/Interface/")
#define DRAW_PATH  ("Images/")
#define MUSIC_PATH ("Music/")
#define FONT_PATH  ("Font/")
#define MONSTER_PATH ("Images/Monstres/")
#define FOND_PATH ("Images/Fond/")
#define MOUCHE_PATH ("Images/Monstres/Mouches/")
#define PIZZA_PATH ("Images/Monstres/Pizzas/")
#define MOTHER_PATH ("Images/Monstres/Mother/")
#define TOWER_PATH ("Images/Tourelles/")
#define POISON_PATH ("Images/Tourelles/Antimouche/")
#define ION_PATH ("Images/Tourelles/Ion/")
#define SHOP_PATH ("Images/Shop/")
#define BUTTON_PATH ("Images/Buttons/")
#define MENU_PATH ("Images/Menu/")

#ifdef MVS
    #define RES_PATH ("../LudumDare_37/Res/")
#else
    #define RES_PATH ("../Res/")
#endif

void LoadAll()
{
    // Loading textures
    LoadTexture("PLAY_R", buildPath(RES_PATH, BUTTON_PATH, "PlayButtonR.png"));
    LoadTexture("PLAY_P", buildPath(RES_PATH, BUTTON_PATH, "PlayButtonP.png"));
    LoadTexture("QUIT_R", buildPath(RES_PATH, BUTTON_PATH, "ExitButtonR.png"));
    LoadTexture("QUIT_P", buildPath(RES_PATH, BUTTON_PATH, "ExitButtonP.png"));
    LoadTexture("CSOUND", buildPath(RES_PATH, INTERFACE_PATH, "LenR.png"));

    LoadTexture("EXIT_BR", buildPath(RES_PATH, INTERFACE_PATH, "topBarExitButton_1.png"));
    LoadTexture("EXIT_BP", buildPath(RES_PATH, INTERFACE_PATH, "topBarExitButton_2.png"));
    LoadTexture("OPT_BR", buildPath(RES_PATH, INTERFACE_PATH, "topBarOptionButton_1.png"));
    LoadTexture("OPT_BP", buildPath(RES_PATH, INTERFACE_PATH, "topBarOptionButton_2.png"));
    LoadTexture("SHOP_PAN", buildPath(RES_PATH, SHOP_PATH, "shop_overlay.png"));

    LoadTexture("SHOP_EXIT_R", buildPath(RES_PATH, BUTTON_PATH, "RedCrossR.png"));
    LoadTexture("SHOP_EXIT_P", buildPath(RES_PATH, BUTTON_PATH, "RedCrossP.png"));

    LoadTexture("MENU_BG", buildPath(RES_PATH, MENU_PATH, "MenuBG.png"));



    LoadTexture("REPLAY_R", buildPath(RES_PATH, BUTTON_PATH, "ReplayButtonR.png"));
    LoadTexture("REPLAY_P", buildPath(RES_PATH, BUTTON_PATH, "ReplayButtonP.png"));

    LoadTexture("MAIN_MENU_R", buildPath(RES_PATH, BUTTON_PATH, "MainMenuButtonR.png"));
    LoadTexture("MAIN_MENU_P", buildPath(RES_PATH, BUTTON_PATH, "MainMenuButtonP.png"));

    LoadTexture("BACK_R", buildPath(RES_PATH, BUTTON_PATH, "BackToTheGameButtonR.png"));
    LoadTexture("BACK_P", buildPath(RES_PATH, BUTTON_PATH, "BackToTheGameButtonP.png"));

    LoadTexture("SHOP_ENTER_P", buildPath(RES_PATH, BUTTON_PATH, "ShopButtonP.png"));
    LoadTexture("SHOP_ENTER_R", buildPath(RES_PATH, BUTTON_PATH, "ShopButtonR.png"));

    LoadTexture("SOUND_ON_R",  buildPath(RES_PATH, BUTTON_PATH,  "SoundOnR.png"));
    LoadTexture("SOUND_ON_P",  buildPath(RES_PATH, BUTTON_PATH,  "SoundOnP.png"));
    LoadTexture("SOUND_OFF_R", buildPath(RES_PATH, BUTTON_PATH, "SoundOffR.png"));
    LoadTexture("SOUND_OFF_P", buildPath(RES_PATH, BUTTON_PATH, "SoundOffP.png"));



    LoadTexture("SHOP_BUY", buildPath(RES_PATH, SHOP_PATH, "buy_button.png"));
    LoadTexture("ITEM_BG", buildPath(RES_PATH, SHOP_PATH, "defense_overlay.png"));
    LoadTexture("FLY_COUNTER", buildPath(RES_PATH, SHOP_PATH, "antimouche_overlay.png"));
    LoadTexture("ION_TURRETS", buildPath(RES_PATH, SHOP_PATH, "ion_overlay.png"));
    LoadTexture("UNAVAILABLE", buildPath(RES_PATH, SHOP_PATH, "unavailable_overlay.png"));

    LoadTexture("BACKGROUND", buildPath(RES_PATH, FOND_PATH, "Fond.png"));
    LoadTexture("OVERLAY_ALERT", buildPath(RES_PATH, FOND_PATH, "Overlay_alerte.png"));
    LoadTexture("GAMEOVER", buildPath(RES_PATH, FOND_PATH, "GameOver.png"));
    // Fly texture
    LoadTexture("FLY_1", buildPath(RES_PATH, MOUCHE_PATH, "mouche45.png"));
    LoadTexture("FLY_2", buildPath(RES_PATH, MOUCHE_PATH, "mouche45_2.png"));
    LoadTexture("FLY_3", buildPath(RES_PATH, MOUCHE_PATH, "mouche45_3.png"));
    LoadTexture("SMALL_FLY_1", buildPath(RES_PATH, MOUCHE_PATH, "mouche30.png"));
    LoadTexture("SMALL_FLY_2", buildPath(RES_PATH, MOUCHE_PATH, "mouche30_2.png"));
    LoadTexture("SMALL_FLY_3", buildPath(RES_PATH, MOUCHE_PATH, "mouche30_3.png"));
    LoadTexture("FAT_FLY_1", buildPath(RES_PATH, MOUCHE_PATH, "mouche60.png"));
    LoadTexture("FAT_FLY_2", buildPath(RES_PATH, MOUCHE_PATH, "mouche60_2.png"));
    LoadTexture("FAT_FLY_3", buildPath(RES_PATH, MOUCHE_PATH, "mouche60_3.png"));

	// paper plane texture
	LoadTexture("PAPER_PLANE_1", buildPath(RES_PATH, MONSTER_PATH, "paperplane-veridict.png"));
	LoadTexture("PAPER_PLANE_2", buildPath(RES_PATH, MONSTER_PATH, "paperplane-veridict-2.png"));
	LoadTexture("PAPER_PLANE_3", buildPath(RES_PATH, MONSTER_PATH, "paperplane_death.png"));

	// mother texture
	LoadTexture("MOTHER_1", buildPath(RES_PATH, MOTHER_PATH, "motherPose1-resized.png"));
	LoadTexture("MOTHER_2", buildPath(RES_PATH, MOTHER_PATH, "motherPose2-resized.png"));

    // Pizza texture
    LoadTexture("SMALL_PIZZA_1", buildPath(RES_PATH, PIZZA_PATH, "Pizzas70_1.png"));
    LoadTexture("SMALL_PIZZA_2", buildPath(RES_PATH, PIZZA_PATH, "Pizzas70_2.png"));
    LoadTexture("SMALL_PIZZA_3", buildPath(RES_PATH, PIZZA_PATH, "Pizzas70_3.png"));
    LoadTexture("PIZZA_1", buildPath(RES_PATH, PIZZA_PATH, "Pizzas80_1.png"));
    LoadTexture("PIZZA_2", buildPath(RES_PATH, PIZZA_PATH, "Pizzas80_2.png"));
    LoadTexture("PIZZA_3", buildPath(RES_PATH, PIZZA_PATH, "Pizzas80_3.png"));
    LoadTexture("FAT_PIZZA_1", buildPath(RES_PATH, PIZZA_PATH, "Pizzas90_1.png"));
    LoadTexture("FAT_PIZZA_2", buildPath(RES_PATH, PIZZA_PATH, "Pizzas90_2.png"));
    LoadTexture("FAT_PIZZA_3", buildPath(RES_PATH, PIZZA_PATH, "Pizzas90_3.png"));

    LoadTexture("SCREEN_1", buildPath(RES_PATH, FOND_PATH, "matrix1.png"));
    LoadTexture("SCREEN_2", buildPath(RES_PATH, FOND_PATH, "matrix2.png"));
    LoadTexture("GEEK_1", buildPath(RES_PATH, FOND_PATH, "geekPose1.png"));
    LoadTexture("GEEK_2", buildPath(RES_PATH, FOND_PATH, "geekPose2.png"));

    // Tower texture
    LoadTexture("TURRET_IDLE", buildPath(RES_PATH, POISON_PATH, "poison180.png"));
    LoadTexture("TURRET_SHOOT", buildPath(RES_PATH, POISON_PATH, "poison180-2.png"));
    LoadTexture("PSCHIT_1", buildPath(RES_PATH, POISON_PATH, "pschit1.png"));
    LoadTexture("PSCHIT_2", buildPath(RES_PATH, POISON_PATH, "pschit2.png"));
    LoadTexture("PSCHIT_3", buildPath(RES_PATH, POISON_PATH, "pschit3.png"));

    LoadTexture("ION_IDLE", buildPath(RES_PATH, ION_PATH, "base_Tourelle_Ions_v2_assembly.png"));
	LoadTexture("ION_CANON", buildPath(RES_PATH, ION_PATH, "Canon_tour_resize.png"));
    LoadTexture("ION_SHOOT", buildPath(RES_PATH, ION_PATH, "IonTurretShoot.png"));
    LoadTexture("ION", buildPath(RES_PATH, ION_PATH, "laserLigne.png"));

	// clickEffect
	LoadTexture("CLICK_EFFECT", buildPath(RES_PATH, DRAW_PATH, "testEffect-goodSize.png"));

    // Loading musics
    LoadMusic("MENU", buildPath(RES_PATH, MUSIC_PATH, "Hypnotic_Regret.ogg"));

    // Loading font
    LoadFont("FONT_OVERLAY", buildPath(RES_PATH, FONT_PATH, "yugothib.ttf"));
    LoadFont("FONT", buildPath(RES_PATH, FONT_PATH, "PIXELADE.TTF"));
}

std::string buildPath(std::string const& base, std::string const& path,
                      std::string const& name)
{
    return base + path + name;
}

void LoadTexture(std::string const& key, std::string const& path)
{
    // Getting texture container
    Container <sf::Texture> * p_Tcontainer = Container<sf::Texture>::Instance();

    // Loading
    sf::Texture *_texture = p_Tcontainer->LoadResource(key);

    if(nullptr == _texture)
        return;

    if(!_texture->loadFromFile(path))
        std::cerr << StaticString::STATIC_FAILURE_FNF << std::endl;
}

void LoadMusic(std::string const& key, std::string const& path)
{
    // Getting texture container
    Container <sf::Music> * p_Mcontainer = Container<sf::Music>::Instance();

    // Loading
    sf::Music * _music = p_Mcontainer->LoadResource(key);

    if(nullptr == _music)
        return;

    if(!_music->openFromFile(path))
        std::cerr << StaticString::STATIC_FAILURE_FNF << std::endl;
}

void LoadFont(std::string const& key, std::string const& path)
{
    // Getting texture container
    Container <sf::Font> * p_Fcontainer = Container<sf::Font>::Instance();

    // Loading
    sf::Font * _music = p_Fcontainer->LoadResource(key);

    if(nullptr == _music)
        return;

    if(!_music->loadFromFile(path))
        std::cerr << StaticString::STATIC_FAILURE_FNF << std::endl;
}