/// \file    Shop.hpp
/// \date    11/12/2016
/// \brief
/// \author  Deru-chan
/// \version 0.1.0

#ifndef __SHOP_HPP
#define __SHOP_HPP

#include <Interface/NPanel.hpp>
#include <Interface/NButton.hpp>
#include "View/ShopItem.hpp"

/// \class Shop
/// \brief
class Shop
{
public :

    /// \brief  Default constructor
    explicit Shop();
    
    /// \brief  Default destructor
    virtual ~Shop();

    /// \return A pointer on the shop pan
    NPanel * getShopPan();

private:

    const int SHOP_PAN_POS_X = 230; //< 317 = center
    const int SHOP_PAN_POS_Y = 104;
    const int SHOP_ITEM_OFFSET = 100;

    NPanel m_shop;
    NButton m_shopExit;

    std::vector < ShopItem * > m_items;
};

#endif // __SHOP_HPP