#ifndef __MUSIC_MANAGER_HPP
#define __MUSIC_MANAGER_HPP

#include "SFML/Audio.hpp"
#include "Utils/Updatable.hpp"
#include "Utils/Singleton.hpp"
#include "Interface/Constant.hpp"

/// \class MusicManager
/// \brief
class MusicManager : public Updatable, public Singleton < MusicManager >
{
public :

    /// \brief  Default constructor
    explicit MusicManager();
    
    /// \brief  Default destructor
    virtual ~MusicManager();

    /// \brief  Update the manager
    /// \param  elapsed The elasped time
    virtual void update(double elapsed);

    /// \brief  Play immediately the current music
    void PlayImmediateCurrent();

    /// \brief Pause the current sound
    void PauseCurrent();

    /// \brief Set the current music
    void SetCurrentMusic(std::string const& key);

    /// \brief Fade out the current music then fade in the next one
    /// \param time the fade time
    /// \param next The next music to play
    void FadeInOut(double time, std::string const& next);

private:

    double m_fade;
    double m_elapsed;
    double m_attenuation;

    sf::Music * m_next;
    sf::Music * m_current;

    bool m_fadeOut;
    bool m_fadeIn;
    bool m_pause;
};

#endif // __MUSIC_MANAGER_HPP
