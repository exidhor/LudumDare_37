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
                      SHOP_PAN_POS_X + 578,
                      SHOP_PAN_POS_Y + 8,
                      pTContainer->GetResource("SHOP_EXIT_R"),
                      pTContainer->GetResource("SHOP_EXIT_P"));

    // Creating items
    m_items.push_back(new ShopItem(
            SHOP_PAN_POS_X + SHOP_ITEM_OFFSET,
            SHOP_PAN_POS_Y + SHOP_ITEM_OFFSET - 60,
            1000,
            "FLY_COUNTER",
            "0"));

    m_items.push_back(new ShopItem(
            SHOP_PAN_POS_X + SHOP_ITEM_OFFSET * 4,
            SHOP_PAN_POS_Y + SHOP_ITEM_OFFSET - 60,
            10000,
            "ION_TURRETS",
            "1"));

    m_items.push_back(new ShopItem(
            SHOP_PAN_POS_X + SHOP_ITEM_OFFSET,
            SHOP_PAN_POS_Y + SHOP_ITEM_OFFSET * 3,
            0,
            "UNAVAILABLE",
            "2"));

    m_items.push_back(new ShopItem(
            SHOP_PAN_POS_X + SHOP_ITEM_OFFSET * 4,
            SHOP_PAN_POS_Y + SHOP_ITEM_OFFSET * 3,
            0,
            "UNAVAILABLE",
            "3"));

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

ShopItem * Shop::getItem(unsigned int index)
{
    return m_items[index];
}
