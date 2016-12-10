#pragma once

// Forward declaration
#include <SFML/Graphics.hpp>

#include <vector>
#include "DemoniacObject/DemoniacObject.hpp"

/**
* \class World
* \brief Gather all the GameObject of the Game into this class.
*		  It provides an acces to the GameObject groups (RenderComponent, Physics, ...)
*/
class World
{
public:

	/**
	* \brief	Initialize the GameObject array
	* \param	reserveSize : the size which will be reserved
	*/
	World(unsigned reserveSize = 0);

	void prepare();

	/**
	* \brief   Add a GameObject to the Active GameObject.
	*			Now it can is available for all the Engine
	* \param	gameObject : the GameObject to register
	*/
	void addDemoniacObject(DemoniacObject * demoniacObject);

	void addDecors(sf::Sprite const& decors);

	/**
	* \brief	Return all the GameObject which have a RenderComponent
	*			from the Active GameObject.
	*			It stores them compared to their position.
	* \param	output : all the GameObject found are stored into this vector
	*/
	void getSortedDrawables(std::vector<Drawable*> & output);

	/**
	* \brief	Return all the GameObject which have a PhysicsComponent
	*			from the Active GameObject.
	* \param	output : all the GameObject found are stored into this vector
	*/
	void getDemoniacObjectIn(sf::Vector2f const& position,
							 float radius,
							 std::vector<DemoniacObject*> & output) const;

private:
	/**
	* \brief	Sort the GameObject compared to their position.
	*			The first element has the smallest y in his position.
	* \param	vector : the vector to sort
	*/
	void sort(std::vector<Drawable*>& vector) const;

	void addDecorsToDrawable();

	std::vector<DemoniacObject*> m_activeEnemies;
	std::vector<Drawable*> m_drawables;
	std::vector<Drawable> m_decors;
};
