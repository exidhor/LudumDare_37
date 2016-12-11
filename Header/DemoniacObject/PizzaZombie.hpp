//
// Created by Kraghan on 11/12/2016.
//

#ifndef LUDUMDARE_PIZZAZOMBIE_HPP
#define LUDUMDARE_PIZZAZOMBIE_HPP

#include "DemoniacObject.hpp"

#define PIZZA_LIFE 15
#define PIZZA_SPEED 5
#define PIZZA_DAMAGE 20
#define PIZZA_ARMOR 3
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
