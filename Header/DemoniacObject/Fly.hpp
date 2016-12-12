//
// Created by renaud on 10/12/16.
//

#ifndef LUDUMDARE_FLY_HPP
#define LUDUMDARE_FLY_HPP

#include "DemoniacObject/DemoniacObject.hpp"

#define FLY_LIFE 20
#define FLY_SPEED 4
#define FLY_DAMAGE 2
#define FLY_ARMOR 2
#define FLY_SPRITESWAP 0.05

class Fly : public DemoniacObject
{
public:
    explicit Fly();
    virtual ~Fly() {};
};

class SmallFly : public DemoniacObject
{
public:
    explicit SmallFly();
    virtual ~SmallFly() {};
};

class FatFly : public DemoniacObject
{
public:
    explicit FatFly();
    virtual ~FatFly() {};
};

#endif //LUDUMDARE_FLY_HPP