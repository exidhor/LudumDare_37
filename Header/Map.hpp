//
// Created by renaud on 10/12/16.
//

#ifndef LUDUMDARE_MAP_HPP
#define LUDUMDARE_MAP_HPP

#include <SFML/Graphics.hpp>
#include "Memory/PoolAllocator.hpp"

class Map
{
public:
    Map();

private:
    PoolAllocator<sf::Sprite> spriteAllocator;
};

#endif //LUDUMDARE_MAP_HPP
