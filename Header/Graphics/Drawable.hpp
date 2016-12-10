//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_DRAWABLE_HPP
#define LUDUMDARE_DRAWABLE_HPP


#include <vector>
#include <SFML/Graphics/Sprite.hpp>

class Drawable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Drawable              ();
    virtual             ~Drawable             ();

    void                addSprite             (sf::Sprite* sprite);
    sf::Sprite*         currentSprite;
    void                nextSprite            ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:
    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    std::vector<sf::Sprite*> m_pSprites;
    unsigned                 m_spriteId;
};


#endif //LUDUMDARE_DRAWABLE_HPP