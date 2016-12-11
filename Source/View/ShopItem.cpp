#include <Memory/Container.hpp>
#include "View/ShopItem.hpp"

/* explicit */ ShopItem::ShopItem(int x, int y,
    unsigned price, std::string const& key, std::string const& index)
{
    // Buffering pointer
    Container<sf::Texture> * pTContainer = Container<sf::Texture>::Instance();

    // Creating main pan
    m_item.create("PAN_ITEM", x, y, pTContainer->GetResource("ITEM_BG"));

    // Adding components
    // Image
    m_image.create("PAN_IMAGE", x + 5, y + 5, pTContainer->GetResource(key));

    // Price
    // TODO

    // Button
    // TODO

    // Pushing them back into the panel
    m_item.addComponent(&m_image);
}

/* virtual */ ShopItem::~ShopItem()
{

}

NPanel * ShopItem::getItemPan()
{
    return &m_item;
}
