#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Graphics/Drawable.hpp"
#include <iostream>

class DrawableAllocator
{
public :
	DrawableAllocator(unsigned reservedSize);

	Drawable* constructDrawable();

	bool removeDrawable(Drawable* drawableToRemove);

private :
	std::vector<Drawable> m_drawables;
};