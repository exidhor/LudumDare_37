#include "Spawner.hpp"


Spawner::Spawner(sf::Vector2f const& target)
	: m_difficulty(0)
	, m_itsTimeToSpawn(false)
	, m_timeUntilSpawn(DEFAULT_STARTING_SPAWN_TIME)
	, m_timeBetweenSpawn(DEFAULT_STARTING_SPAWN_TIME)
	, m_target(target)
    , m_token(0)
{
	// nothing
}

void Spawner::updateTime(double time)
{
	m_timeUntilSpawn -= time;

	while(m_timeUntilSpawn <= 0)
	{
		m_timeUntilSpawn = m_timeBetweenSpawn - m_timeUntilSpawn;
		m_itsTimeToSpawn = true;
	}
}

DemoniacObject* Spawner::spawn()
{
	if(m_itsTimeToSpawn)
	{
		m_itsTimeToSpawn = false;

        int token;
        if(m_token < 120)
            token = rand() % m_token;
        else
            token = rand() % 120;

        token = getHighestTokenCost(token);

        DemoniacObject * ptr = createDemoniacObjectWithToken(token);

        m_token-=token;

        // ajout du path
        for(unsigned i = 0; i < m_route.size(); i++)
        {
            ptr->addPath(m_route[i]);
        }
        ptr->setCurrentPath(&m_route[0]);

        return ptr;

	}

	return nullptr;
}

bool Spawner::isReadyToSpawn() const
{
	return m_itsTimeToSpawn;
}

void Spawner::setDifficulty(unsigned difficulty)
{
	m_difficulty = difficulty;
}

void Spawner::increaseDifficulty()
{
	m_difficulty++;
}

void Spawner::setTimeBetweenSpawn(double time)
{
	m_timeBetweenSpawn = time;
}

void Spawner::setPosition(sf::Vector2f const& position)
{
	m_position = position;
	m_route.clear();
}

sf::Vector2f const& Spawner::getPosition() const
{
	return m_position;
}

void Spawner::addPath(Path path)
{
    m_route.push_back(path);
}

unsigned Spawner::getDifficulty()
{
    return m_difficulty;
}

bool Spawner::outOfToken()
{
    return m_token <= 0;
}

void Spawner::giveToken()
{
    m_token = (long) (10 + m_difficulty * 10);

    if(m_timeBetweenSpawn > 0.1)
        m_timeBetweenSpawn -= 0.05;
}

int Spawner::getHighestTokenCost(int token)
{
    // Respecter la hierarchie ! Du plus grand au plus petit !

        // Mom
	if (m_difficulty > 14 && token >= 100)
		return 100;
        // Fat Pizza
    if(m_difficulty > 9 && token >= 40)
        return 40;
        // Small Pizza
    else if(m_difficulty > 6 && token >= 35)
        return 35;
        // Pizza
    else if(m_difficulty > 5 && token >= 30)
        return 30;
        // Small Fly
	else if (m_difficulty > 4 && token >= 20)
		return 20;
        // Fat Fly
	else if (m_difficulty > 2 && token >= 10)
		return 15;
        // Fly
	else if (m_difficulty > 1 && token >= 5)
		return 5;
        // Paper plane
    else
        return 1;
}

DemoniacObject *Spawner::createDemoniacObjectWithToken(int token)
{
    switch(token)
    {
        case 1 :
			return new PaperPlane();
        case 5 :
            return new Fly();
        case 15 :
            return new FatFly();
		case 20 :
			return new SmallFly();
        case 30 :
            return new PizzaZombie();
        case 35 :
            return new SmallPizzaZombie();
        case 40 :
            return new FatPizzaZombie();
		case 100 :
			return new Mom();
        default:
        std::cerr<< "Unknown token value : " << token << std::endl;
			return new Fly();
    }
}