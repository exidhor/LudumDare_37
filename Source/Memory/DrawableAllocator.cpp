#include "Memory/DrawableAllocator.hpp"


DrawableAllocator::DrawableAllocator(unsigned reservedSize)
{
	m_drawables.reserve(reservedSize);
}

Drawable* DrawableAllocator::constructDrawable()
{
	m_drawables.emplace_back(Drawable());

	return &m_drawables.back();
}

bool DrawableAllocator::removeDrawable(Drawable* drawableToRemove)
{
	for(int i = 0; i <  m_drawables.size(); i++)
	{
		if(&m_drawables[i] == drawableToRemove)
		{
			m_drawables.erase(m_drawables.begin() + i);
			return true;
		}
	}

	std::cerr << "can't find drawable to remove in DrawableAllocator" << std::endl;

	return false;
}