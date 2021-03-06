//
// Created by Kraghan on 10/12/2016.
//

#include "Memory/PoolAllocator.hpp"
#include "Graphics/Drawable.hpp"

/* Explicit */
Drawable::Drawable()
	: m_textureId(0)
	  , m_deathTexture(nullptr)
	  , isDead(false)
	  , m_layer(DEFAULT_LAYER)
{
	// None
}

/* Virtual */
Drawable::~Drawable()
{
}

void Drawable::addTexture(sf::Texture* texture)
{
	m_pTextures.push_back(texture);
}

sf::Sprite& Drawable::getSprite()
{
	return m_sprite;
}

sf::Sprite const& Drawable::getSprite() const
{
	return m_sprite;
}

void Drawable::nextTexture()
{
	if (!isDead)
	{
		++m_textureId;
		if (m_textureId >= m_pTextures.size())
			m_textureId = 0;

		m_sprite.setTexture(*m_pTextures[m_textureId], true);

		centerOrigin();
	}
}

void Drawable::setDeathTexture(sf::Texture* texture)
{
	m_deathTexture = texture;
}

void Drawable::activeDeathSprite()
{
	isDead = true;
	m_sprite.setTexture(*m_deathTexture);
	m_layer = DEATH_LAYER;
	centerOrigin();
}

void Drawable::centerOrigin()
{
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2,
	                   m_sprite.getGlobalBounds().height / 2);
}

unsigned Drawable::getLayer() const
{
	return m_layer;
}

void Drawable::setLayer(unsigned layer)
{
	m_layer = layer;
}