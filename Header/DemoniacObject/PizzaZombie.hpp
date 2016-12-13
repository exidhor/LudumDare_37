//
// Created by Kraghan on 11/12/2016.
//

#ifndef LUDUMDARE_PIZZAZOMBIE_HPP
#define LUDUMDARE_PIZZAZOMBIE_HPP

#include "DemoniacObject.hpp"

#define PIZZA_LIFE 100
#define PIZZA_SPEED 7
#define PIZZA_DAMAGE 10
#define PIZZA_ARMOR 4
#define PIZZA_SPRITESWAP 0.10

class PizzaZombie : public DemoniacObject
{
public:
    explicit PizzaZombie();
    virtual ~PizzaZombie() {};
};

class SmallPizzaZombie : public DemoniacObject
{
public:
    explicit SmallPizzaZombie();
    virtual ~SmallPizzaZombie() {};
};

class FatPizzaZombie : public DemoniacObject
{
public:
    explicit FatPizzaZombie();
    virtual ~FatPizzaZombie() {};
};

#endif //LUDUMDARE_PIZZAZOMBIE_HPP
