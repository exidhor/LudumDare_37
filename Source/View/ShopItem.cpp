#include <Utils/Patch.hpp>
#include "View/ShopItem.hpp"
#include <Memory/Container.hpp>


/* explicit */ ShopItem::ShopItem(int x, int y,
    unsigned price, std::string const& key, std::string const& index)
{
    m_uprice = price;

    // Buffering pointer
    Container<sf::Font> * pFContainer = Container<sf::Font>::Instance();
    Container<sf::Texture> * pTContainer = Container<sf::Texture>::Instance();

    // Creating main pan
    m_item.create("PAN_ITEM", x, y, pTContainer->GetResource("ITEM_BG"));

    // Adding components
    // Image
    m_image.create("PAN_IMAGE", x, y, pTContainer->GetResource(key));

    // Price
    m_price.create("PAN_PRICE", x + 30, y + 140, 25,
                   pFContainer->GetResource("FONT"),
                   fix::to_string(price), sf::Color::White);

    // Button
    if(price != 0)
        m_buy.create(std::string("BUY_") + fix::to_string(index),
                     x + 8, y + 180,
                     pTContainer->GetResource("SHOP_BUY"),
                     pTContainer->GetResource("SHOP_BUY"));


    // Pushing them back into the panel
    m_item.addComponent(&m_image);
    m_item.addComponent(&m_price);
    m_item.addComponent(&m_buy);
}

/* virtual */ ShopItem::~ShopItem()
{
    // None
}

NPanel * ShopItem::getItemPan()
{
    return &m_item;
}

unsigned int ShopItem::getPrice()
{
    return m_uprice;
}
