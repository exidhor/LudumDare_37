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

    void                addTexture             (sf::Texture * texture);
	sf::Sprite&         getSprite();
	sf::Sprite const&   getSprite() const;
    void                nextTexture            ();
    void                setDeathTexture        (sf::Texture * texture);
    void                activeDeathSprite     ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:
    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:

	void centerOrigin();

	sf::Sprite               m_sprite;
    std::vector<sf::Texture*> m_pTextures;
    unsigned                 m_textureId;
	sf::Texture*             m_deathTexture;
	bool                     isDead;
};


#endif //LUDUMDARE_DRAWABLE_HPP
