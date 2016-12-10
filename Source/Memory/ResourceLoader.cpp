#include <SFML/Graphics/Texture.hpp>

#include "Memory/Container.hpp"
#include "Memory/ResourceLoader.hpp"

#define INTERFACE_PATH ("Images/Interface/")

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

