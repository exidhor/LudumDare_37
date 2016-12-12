//
// Created by Kraghan on 12/12/2016.
//

#include <Memory/Container.hpp>
#include <MathHelper.hpp>
#include "Player/IonShoot.hpp"

IonShoot::IonShoot()
: Projectile(SPEED_ION)
{
    getDrawable().addTexture(Container<sf::Texture>::Instance()->GetResource("ION"));
    getDrawable().nextTexture();
}

void IonShoot::killDemoniacObject(const World world)
{
    std::vector<DemoniacObject*> targets;
    world.getDemoniacObjectIn(getDrawable().getSprite().getPosition(), 10, targets);

    if (targets.size() > 0)
    {
        for (int i = 0; i < (int) targets.size(); i++)
        {
            targets[i]->hit(DAMAGE_ION);
        }
    }
}

sf::Vector2f IonShoot::move(sf::Vector2f const &position, float speed)
{
    // TODO J'en sais foutrement rien
    return position*speed;
}
