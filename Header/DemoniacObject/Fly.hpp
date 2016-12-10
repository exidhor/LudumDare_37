//
// Created by renaud on 10/12/16.
//

#ifndef LUDUMDARE_FLY_HPP
#define LUDUMDARE_FLY_HPP

#include "DemoniacObject/DemoniacObject.hpp"

#define FLY_LIFE 10
#define FLY_SPEED 1
#define FLY_DAMAGE 10
#define FLY_ARMOR 0
#define FLY_SPRITESWAP 0.05

class Fly : public DemoniacObject
{
public:
    explicit Fly();
};

#endif //LUDUMDARE_FLY_HPP