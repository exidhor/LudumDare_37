#include <Memory/PoolAllocator.hpp>
#include "World.hpp"
#include "MathHelper.hpp"

World::World(unsigned reserveSize)
{
	m_activeEnemies.reserve(reserveSize);
}

World::~World()
{
    for (auto object : m_decors)
    {
        PoolAllocator<sf::Sprite>::Instance()->Deallocate(object.currentSprite);
    }
}

void World::prepare()
{
	m_activeEnemies.clear();
	m_drawables.clear();

	addDecorsToDrawable();
}

void World::draw(sf::RenderTarget & target)
{
	std::vector<Drawable*> toDraw;
	getSortedDrawables(toDraw);

	for(unsigned int i = 0; i < toDraw.size(); i++)
	{
		target.draw(*toDraw[i]->currentSprite);
	}
}

void World::addDemoniacObject(DemoniacObject * demoniacObject)
{
	m_activeEnemies.push_back(demoniacObject);
	m_drawables.push_back((Drawable *&&) demoniacObject);
}

void World::addDecors(sf::Vector2f const& position, sf::Texture *texture)
{
	sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setPosition(position);
    sprite->setTexture(*texture);
    Drawable drawable;
    drawable.addSprite(sprite);
    drawable.nextSprite();

    m_decors.push_back(drawable);
}

void World::addBackground(sf::Texture *texture)
{
    sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    sprite->setTexture(*texture);
    m_background.addSprite(sprite);
    m_background.nextSprite();

    m_drawables.push_back(&m_background);
}

void World::getSortedDrawables(std::vector<Drawable*> & output)
{
	for (unsigned i = 0; i < m_activeEnemies.size(); i++)
	{
		output.push_back((Drawable *&&) m_activeEnemies[i]);
	}

    for (unsigned i = 0; i < m_decors.size(); i++)
    {
        output.push_back(&m_decors[i]);
    }

    output.push_back(&m_background);

	sort(output);
}

void World::getDemoniacObjectIn(sf::Vector2f const& position,
								float radius,
								std::vector<DemoniacObject*> & output) const
{
	for (unsigned i = 0; i < m_activeEnemies.size(); i++)
	{
		if (MathHelper::isColliding(m_activeEnemies[i]->currentSprite->getGlobalBounds(),
			                        position,
			                        radius))
		{
			output.push_back(m_activeEnemies[i]);
		}
	}
}

void World::sort(std::vector<Drawable*>& vector) const
{
	struct
	{
		bool operator()(Drawable* a, Drawable* b)
		{
			sf::Vector2f const& a_position = a->currentSprite->getPosition();
			sf::Vector2f const& b_position = b->currentSprite->getPosition();

			if (a_position.y < b_position.y)
			{
				return true;
			}

			if (a_position.y == b_position.y)
			{
				return a_position.x < b_position.x;
			}

			return false;
		}

	} compare;


	std::sort(vector.begin(), vector.end(), compare);
}

void World::addDecorsToDrawable()
{
	for(unsigned int i = 0; i < m_decors.size(); i++)
	{
		m_drawables.push_back(&m_decors[i]);
	}
}