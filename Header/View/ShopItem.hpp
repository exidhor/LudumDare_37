/// \file    ShopItem.hpp
/// \date    11/12/2016
/// \brief   Nope
/// \author  Aredhele
/// \version 0.1.0

#ifndef __SHOP_ITEM_HPP
#define __SHOP_ITEM_HPP

#include <Interface/NPanel.hpp>
#include <Interface/NLabel.hpp>
#include <Interface/NButton.hpp>

/// \class ShopItem
/// \brief Nope too
class ShopItem
{
public :

    /// \brief  Default constructor
    explicit ShopItem(int x, int y, unsigned price, std::string const& key,
                      std::string const& index);
    
    /// \brief  Default destructor
    virtual ~ShopItem();

    /// \return The item panel
    NPanel * getItemPan();

    unsigned int getPrice();

private:

    NPanel m_item;
    NPanel m_image;
    NLabel m_price;
    NButton m_buy;

    unsigned int m_uprice;
};

#endif // __SHOP_ITEM_HPP