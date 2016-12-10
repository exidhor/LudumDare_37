/**
 * \brief Manage all musics & sounds
 * \file MusicManager.hpp
 * \author Aredhele
 * \version 0.1
 * \date 13/12/2015
 * \class MusicManager.cpp
 */

#ifndef DEF_MUSIC_MANAGER_HPP
#define DEF_MUSIC_MANAGER_HPP

#include <map>
#include <string>

#include "Interface/Playlist.hpp"
#include "Interface/Manager.hpp"

class MusicManager : public Manager
{
    private:
        std::vector < std::string > m_keyList;
        std::map < std::string, Playlist * > m_playlistMap;

        std::vector < sf::SoundBuffer * > m_soundBufferList;
        std::map < std::string, sf::Sound * > m_soundMap;

        unsigned int m_currentPlaylist;

        // Methods
        int findIndex(std::string key);

    public:
        // Constructor
        MusicManager(bool debug);

        // Destructor
        ~MusicManager();

        // Methods
        void update();
        void playSound(std::string key);

        void startPlaylist(std::string key);
        void stopPlaylist();

        void createPlaylist(std::string key, int volume, bool loop, float pitch);
        void createSound(std::string path, std::string key, int volume, float pitch);

        // Getters
        Playlist * getPlaylist();
        Playlist * getPlaylist(std::string key);
};

#endif // DEF_MUSIC_MANAGER_HPP
