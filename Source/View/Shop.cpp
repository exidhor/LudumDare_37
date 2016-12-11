#include "View/Shop.hpp"
#include "Memory/Container.hpp"

/* explicit */ Shop::Shop()
{
    // Buffering pointer
    Container<sf::Texture> * pTContainer = Container<sf::Texture>::Instance();

    // Main panel
    m_shop.create("SHOP_PAN",
                  SHOP_PAN_POS_X,
                  SHOP_PAN_POS_Y,
                  pTContainer->GetResource("SHOP_PAN"));

    // Exit button
    m_shopExit.create("SHOP_EXIT",
                      SHOP_PAN_POS_X,
                      SHOP_PAN_POS_Y,
                      pTContainer->GetResource("SHOP_PAN"),
                      pTContainer->GetResource("SHOP_PAN"));
}

/* explicit */ Shop::~Shop()
{

}

NPanel * Shop::getShopPan()
{
    return &m_shop;
}
