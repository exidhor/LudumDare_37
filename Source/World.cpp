#include <Memory/PoolAllocator.hpp>
#include "World.hpp"
#include "MathHelper.hpp"

World::World(unsigned reserveSize)
{
	m_activeEnemies.reserve(reserveSize);
}

World::~World()
{
    //for (auto object : m_decors)
    //{
     //   PoolAllocator<sf::Sprite>::Instance()->Deallocate(object.currentSprite);
    //}
    //PoolAllocator<sf::Sprite>::Instance()->Deallocate(m_background.currentSprite);
}

void World::prepare()
{
	m_activeEnemies.clear();
	m_drawables.clear();
	m_corpses.clear();
	m_canon.clear();

	addDecorsToDrawable();
}

void World::draw(sf::RenderTarget & target)
{
	std::vector<Drawable*> toDraw;
	getSortedDrawables(toDraw);

	target.draw(m_background.getSprite());

	for(unsigned int i = 0; i < toDraw.size(); i++)
	{
		target.draw(toDraw[i]->getSprite());
	}
}

void World::addDemoniacObject(DemoniacObject * demoniacObject)
{
	m_activeEnemies.push_back(demoniacObject);

	if (demoniacObject->getDrawable().getLayer() == DEATH_LAYER)
	{
		// we handle them into the corpses vector
		m_corpses.push_back(&demoniacObject->getDrawable());
	}
	else
	{
		m_drawables.push_back(&demoniacObject->getDrawable());
	}
}

void World::addDrawable(Drawable * drawable)
{
	if(drawable->getLayer() == CANON_LAYER)
	{
		m_canon.push_back(drawable);
	}
	else
	{
		m_drawables.push_back(drawable);
	}
}

void World::addDecors(sf::Vector2f const& position, sf::Texture *texture)
{
	//sf::Sprite *sprite = PoolAllocator<sf::Sprite>::Instance()->Allocate();
    //sprite->setPosition(position);
    //sprite->setTexture(*texture);
    //Drawable drawable;
    //drawable.addTexture(sprite);
    //drawable.nextTexture();

    //m_decors.push_back(drawable);
}

void World::addBackground(sf::Texture *texture)
{
    m_background.addTexture(texture);
    m_background.nextTexture();

	m_background.getSprite().setOrigin(0, 0);

    //m_drawables.push_back(&m_background);
}

void World::getSortedDrawables(std::vector<Drawable*> & output)
{
	for (unsigned i = 0; i < m_decors.size(); i++)
	{
		output.push_back(&m_decors[i]);
	}

	sort(m_corpses);
	sort(m_drawables);
	sort(m_canon);

	for (unsigned i = 0; i < m_corpses.size(); i++)
	{
		output.push_back(m_corpses[i]);
	}

	for (unsigned i = 0; i < m_drawables.size(); i++)
	{
		output.push_back(m_drawables[i]);
	}

	for (unsigned i = 0; i < m_canon.size(); i++)
	{
		output.push_back(m_canon[i]);
	}
}

void World::getDemoniacObjectIn(sf::Vector2f const& position,
								float radius,
								std::vector<DemoniacObject*> & output) const
{
	for (unsigned i = 0; i < m_activeEnemies.size(); i++)
	{
		if (!m_activeEnemies[i]->isDead() &&
			MathHelper::isColliding(m_activeEnemies[i]->getDrawable().getSprite().getGlobalBounds(),
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
			sf::Vector2f const& a_position = a->getSprite().getPosition() + sf::Vector2f(a->getSprite().getGlobalBounds().width / 2,
																							a->getSprite().getGlobalBounds().height / 2);
			sf::Vector2f const& b_position = b->getSprite().getPosition() + sf::Vector2f(b->getSprite().getGlobalBounds().width / 2,
																							b->getSprite().getGlobalBounds().height / 2);;

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