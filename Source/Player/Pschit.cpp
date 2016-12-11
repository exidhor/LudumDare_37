//
// Created by renaud on 11/12/16.
//

#include <Memory/Container.hpp>
#include <World.hpp>
#include "Player/Pschit.hpp"

Pschit::Pschit()
    : Projectile(SPEED)
{
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PSCHIT_1"));
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PSCHIT_2"));
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("PSCHIT_3"));
	getDrawable().nextTexture();
}

sf::Vector2f Pschit::move(sf::Vector2f const &position, float speed)
{
    return position;
}

void Pschit::killDemoniacObject(const World world)
{
    std::vector<DemoniacObject*> targets;
    world.getDemoniacObjectIn(getDrawable().getSprite().getPosition(), 10, targets);

    if (targets.size() > 0)
    {
        for (int i = 0; i < (int) targets.size(); i++)
        {
            targets[i]->hit(DAMAGE);
        }
    }
}