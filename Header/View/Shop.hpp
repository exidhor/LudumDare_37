/// \file    Shop.hpp
/// \date    11/12/2016
/// \brief
/// \author  Aredhele
/// \version 0.1.0

#ifndef __SHOP_HPP
#define __SHOP_HPP

#include <Interface/NPanel.hpp>
#include <Interface/NButton.hpp>

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

    const int SHOP_PAN_POS_X = 317;
    const int SHOP_PAN_POS_Y = 104;

    NPanel m_shop;
    NButton m_shopExit;
};

#endif // __SHOP_HPP