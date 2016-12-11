#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Memory/Container.hpp"
#include "Memory/ResourceLoader.hpp"

#define INTERFACE_PATH ("Images/Interface/")
#define DRAW_PATH  ("Images/")
#define MUSIC_PATH ("Music/")
#define FONT_PATH  ("Font/")

#ifdef MVS
    #define RES_PATH ("../LudumDare_37/Res/")
#else
    #define RES_PATH ("../Res/")
#endif

void LoadAll()
{
    // Loading textures
    LoadTexture("PLAY_R", buildPath(RES_PATH, INTERFACE_PATH, "PlayR.png"));
    LoadTexture("PLAY_P", buildPath(RES_PATH, INTERFACE_PATH, "PlayP.png"));
    LoadTexture("QUIT_R", buildPath(RES_PATH, INTERFACE_PATH, "QuitR.png"));
    LoadTexture("QUIT_P", buildPath(RES_PATH, INTERFACE_PATH, "QuitP.png"));
    LoadTexture("CSOUND", buildPath(RES_PATH, INTERFACE_PATH, "LenR.png"));

    LoadTexture("EXIT_BR", buildPath(RES_PATH, INTERFACE_PATH, "topBarExitButton_1.png"));
    LoadTexture("EXIT_BP", buildPath(RES_PATH, INTERFACE_PATH, "topBarExitButton_2.png"));
    LoadTexture("OPT_BR", buildPath(RES_PATH, INTERFACE_PATH, "topBarOptionButton_1.png"));
    LoadTexture("OPT_BP", buildPath(RES_PATH, INTERFACE_PATH, "topBarOptionButton_2.png"));

    LoadTexture("BACKGROUND", buildPath(RES_PATH, DRAW_PATH, "FondRempli.png"));
    LoadTexture("FLY_1", buildPath(RES_PATH, DRAW_PATH, "mouche45.png"));
    LoadTexture("FLY_2", buildPath(RES_PATH, DRAW_PATH, "mouche45_2.png"));
    LoadTexture("FLY_3", buildPath(RES_PATH, DRAW_PATH, "mouche45_3.png"));
    LoadTexture("SMALL_FLY_1", buildPath(RES_PATH, DRAW_PATH, "mouche30.png"));
    LoadTexture("SMALL_FLY_2", buildPath(RES_PATH, DRAW_PATH, "mouche30_2.png"));
    LoadTexture("SMALL_FLY_3", buildPath(RES_PATH, DRAW_PATH, "mouche30_3.png"));
    LoadTexture("FAT_FLY_1", buildPath(RES_PATH, DRAW_PATH, "mouche60.png"));
    LoadTexture("FAT_FLY_2", buildPath(RES_PATH, DRAW_PATH, "mouche60_2.png"));
    LoadTexture("FAT_FLY_3", buildPath(RES_PATH, DRAW_PATH, "mouche60_3.png"));

    LoadTexture("SCREEN_1", buildPath(RES_PATH, DRAW_PATH, "matrix1.png"));
    LoadTexture("SCREEN_2", buildPath(RES_PATH, DRAW_PATH, "matrix2.png"));
    LoadTexture("GEEK_1", buildPath(RES_PATH, DRAW_PATH, "geekPose1.png"));
    LoadTexture("GEEK_2", buildPath(RES_PATH, DRAW_PATH, "geekPose2.png"));
    LoadTexture("TURRET_IDLE", buildPath(RES_PATH, DRAW_PATH, "poison180.png"));
    LoadTexture("TURRET_SHOOT", buildPath(RES_PATH, DRAW_PATH, "poison180-2.png"));

    // Loading musics
    LoadMusic("MENU", buildPath(RES_PATH, MUSIC_PATH, "Hypnotic_Regret.ogg"));

    // Loading font
    LoadFont("FONT", buildPath(RES_PATH, FONT_PATH, "GEEKT___.TTF"));
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