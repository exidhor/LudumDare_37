//
// Created by Kraghan on 11/12/2016.
//

#ifndef LUDUMDARE_PIZZAZOMBIE_HPP
#define LUDUMDARE_PIZZAZOMBIE_HPP

#include "DemoniacObject.hpp"

#define PIZZA_LIFE 10
#define PIZZA_SPEED 4
#define PIZZA_DAMAGE 10
#define PIZZA_ARMOR 0
#define PIZZA_SPRITESWAP 0.10

class PizzaZombie : public DemoniacObject
{
public:
    explicit PizzaZombie();
    virtual ~PizzaZombie() {};
};


#endif //LUDUMDARE_PIZZAZOMBIE_HPP
