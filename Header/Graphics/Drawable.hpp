//
// Created by Kraghan on 10/12/2016.
//

#ifndef LUDUMDARE_DRAWABLE_HPP
#define LUDUMDARE_DRAWABLE_HPP

#define DEFAULT_LAYER 10
#define CANON_LAYER 20
#define DEATH_LAYER 0

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

	unsigned            getLayer() const;
	void                setLayer(unsigned layer);

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
	unsigned                 m_layer; // NON CE NEST PAS LE LAYER QUE TU CONNAIS JORDAN
};


#endif //LUDUMDARE_DRAWABLE_HPP
