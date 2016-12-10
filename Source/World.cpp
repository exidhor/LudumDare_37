#include "World.hpp"

World::World(unsigned reserveSize)
{
	m_activeEnemies.reserve(reserveSize);
}

void World::prepare()
{
	m_activeEnemies.clear();
	m_drawables.clear();

	addDecorsToDrawable();
}

void World::addDemoniacObject(DemoniacObject * demoniacObject)
{
	m_activeEnemies.push_back(demoniacObject);
	m_drawables.push_back(demoniacObject);
}

void World::addDecors(sf::Sprite const& decors)
{
	// todo
	//m_decors.push_back()
	//m_drawables.push_back()
}

void World::getSortedDrawables(std::vector<Drawable*> & output)
{
	for (unsigned i = 0; i < m_activeEnemies.size(); i++)
	{
		output.push_back(m_activeEnemies[i]);
	}

	sort(output);
}

void World::getDemoniacObjectIn(sf::Vector2f const& position,
								float radius,
								std::vector<DemoniacObject*> & output) const
{
	for (unsigned i = 0; i < m_activeEnemies.size(); i++)
	{
		// todo
		//if (m_active[i]->GetComponent<PhysicsComponent>() != nullptr)
		//{
		//	output.push_back(m_active[i]);
		//}
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
	for(int i = 0; i < m_decors.size(); i++)
	{
		m_drawables.push_back(&m_decors[i]);
	}
}