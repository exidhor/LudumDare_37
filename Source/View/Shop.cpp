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
                      SHOP_PAN_POS_X + 605,
                      SHOP_PAN_POS_Y + 8,
                      pTContainer->GetResource("SHOP_EXIT"),
                      pTContainer->GetResource("SHOP_EXIT"));

    // Creating items
    m_items.push_back(new ShopItem(
            SHOP_PAN_POS_X + SHOP_ITEM_OFFSET,
            SHOP_PAN_POS_Y + SHOP_ITEM_OFFSET - 60,
            1000,
            "FLY_COUNTER",
            "1"));

    m_items.push_back(new ShopItem(
            SHOP_PAN_POS_X + SHOP_ITEM_OFFSET * 4,
            SHOP_PAN_POS_Y + SHOP_ITEM_OFFSET - 60,
            10000,
            "FLY_COUNTER",
            "2"));

    m_items.push_back(new ShopItem(
            SHOP_PAN_POS_X + SHOP_ITEM_OFFSET,
            SHOP_PAN_POS_Y + SHOP_ITEM_OFFSET * 3,
            100000,
            "FLY_COUNTER",
            "3"));

    m_items.push_back(new ShopItem(
            SHOP_PAN_POS_X + SHOP_ITEM_OFFSET * 4,
            SHOP_PAN_POS_Y + SHOP_ITEM_OFFSET * 3,
            1000000,
            "FLY_COUNTER",
            "4"));

    // Adding items
    for(unsigned i = 0; i < m_items.size(); ++i)
        m_shop.addComponent(m_items[i]->getItemPan());

    // Add exit button
    m_shop.addComponent(&m_shopExit);
}

/* explicit */ Shop::~Shop()
{
    for(unsigned i = 0; i < m_items.size(); ++i)
        delete m_items[i];
}

NPanel * Shop::getShopPan()
{
    return &m_shop;
}