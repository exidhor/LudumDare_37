#include "DemoniacObject/PaperPlane.hpp"

PaperPlane::PaperPlane()
	: DemoniacObject(sf::Vector2f(),
					 PAPER_PLANE_LIFE,
					 PAPER_PLANE_SPEED,
					 PAPER_PLANE_DAMAGE,
					 PAPER_PLANE_ARMOR,
					 PAPER_PLANE_SPRITESWAP)
{
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PAPER_PLANE_1"));
	getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PAPER_PLANE_2"));
	getDrawable().setDeathTexture(Container<sf::Texture>::Instance()->GetResource("PAPER_PLANE_3"));
	getDrawable().nextTexture();
	setKillIncome(PAPER_PLANE_INCOME);
}
