#include "Memory/Container.hpp"
#include "Music/MusicManager.hpp"

/* explicit */ MusicManager::MusicManager()
: m_fade(0.0)
, m_elapsed(0.0)
, m_attenuation(0.0)
, m_next(nullptr)
, m_current(nullptr)
, m_fadeOut(false)
, m_fadeIn(false)
, m_pause(false)

{
    // None
}

/* virtual */ MusicManager::~MusicManager()
{
    if(m_current != nullptr)
        m_current->stop();

    if(m_next != nullptr)
        m_next->stop();
}

void MusicManager::update(double elapsed)
{
    m_elapsed += elapsed;

    if(m_fadeOut)
    {
        m_current->setVolume(
                m_current->getVolume() - (float)(m_attenuation * elapsed));

        if(m_elapsed >= m_fade)
        {
            m_fadeIn = true;
            m_fadeOut = false;
            m_current->stop();

            // Swap
            m_elapsed = 0;
            m_current = m_next;
            m_next = nullptr;
            m_current->setVolume(0);
            m_current->setLoop(true);
            m_current->play();
        }
    }

    if(m_fadeIn)
    {
        m_current->setVolume(
                m_current->getVolume() + (float)(m_attenuation * elapsed));

        if(m_elapsed >= m_fade)
        {
            m_fadeIn = false;
            m_elapsed = 0;
        }
    }
}

void MusicManager::SetCurrentMusic(std::string const& key)
{
    m_current = Container<sf::Music>::Instance()->GetResource(key);
}

void MusicManager::FadeInOut(double time, std::string const &next)
{
    m_next = Container<sf::Music>::Instance()->GetResource(next);

    m_fade = time;
    m_elapsed = 0.0;

    if(m_current == nullptr)
    {
        m_current = m_next;
        m_fadeOut = false;
        m_fadeIn = true;

        m_current->setVolume(50);
        m_attenuation = m_current->getVolume() / m_fade;
        m_current->setVolume(0);
        m_current->play();
    }
    else
    {
        m_fadeOut = true;
        m_current->setVolume(50);
        m_attenuation = m_current->getVolume() / m_fade;
    }
}

void MusicManager::PlayImmediateCurrent()
{
    if(m_current != nullptr)
    {
        m_current->play();
    }
}

void MusicManager::PauseCurrent()
{
    if(m_current != nullptr)
    {
        if(!m_pause)
        {
            m_current->pause();
            m_pause = true;
        }
        else
        {
            m_current->play();
            m_pause = false;
        }
    }
}



