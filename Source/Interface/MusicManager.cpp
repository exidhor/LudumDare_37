/**
 * \brief Manage all musics & sounds
 * \file MusicManager.cpp
 * \author Aredhele
 * \version 0.1
 * \date 13/12/2015
 * \class MusicManager.hpp
 */

#include "Interface/MusicManager.hpp"

/*!
 * \brief Constructor
 * \param debug The debug mode
 */
MusicManager::MusicManager(bool debug) : Manager() {
    m_debug = debug;
    m_currentPlaylist = 0;
}

/**
 * \brief Destructor
 */
MusicManager::~MusicManager() {
    // Cleaning all
    m_playlistMap.clear();
    m_soundMap.clear();
    m_soundBufferList.clear();
}

/**
 * \brief Create an empty playlist
 * \param key the key to reference the playlist
 * \param volume the global volume
 * \param loop loop number to play the playlist
 * \param pitch global frequency of the playlist
 */
void MusicManager::createPlaylist(std::string key, int volume, bool loop, float pitch) {

    m_playlistMap.insert(std::pair < std::string, Playlist * >
    (key, new Playlist(m_debug, volume, loop, pitch)));

    m_keyList.push_back(key);
}

/**
 * \brief create a sound from a sound memory buffer
 * \param path the path to the sound
 * \param key The key to find the sound in map
 * \param volume the volume of the sound
 * \param pitch the pitch of the sound
 */
void MusicManager::createSound(std::string path, std::string key, int volume, float pitch) {
    sf::SoundBuffer * ptr_soundBuffer = nullptr;
    sf::Sound * ptr_sound = nullptr;

    // Loading buffer
    ptr_soundBuffer = new sf::SoundBuffer();
    ptr_sound = new sf::Sound();

    if(!ptr_soundBuffer->loadFromFile(path)) {
        if(m_debug)
            std::cerr << "- Failed to load sound buffer from memory" << std::endl;
        return;
    }

    ptr_sound->setBuffer(*ptr_soundBuffer);
    ptr_sound->setVolume(volume);
    ptr_sound->setPitch(pitch);

    m_soundBufferList.push_back(ptr_soundBuffer);

    m_soundMap.insert(std::pair < std::string, sf::Sound * >
    (key, ptr_sound));

    if(m_debug)
        std::cout << "- Sound successfully loaded !" << std::endl;
}

/**
 * \brief start the specified playlist
 * \param key the key of the map
 */
void MusicManager::startPlaylist(std::string key) {

    // Make sure of the current playlist is stopped
    // Updating current index
    stopPlaylist();
    m_currentPlaylist = findIndex(key);

    m_playlistMap[key]->load();
    if(m_debug)
	   std::cout << "- Start playlist : " << key << std::endl;
}

/*!
 * \brief Stop the current playlist
 */
void MusicManager::stopPlaylist() {
    if(!m_playlistMap[m_keyList[m_currentPlaylist]]->isFinished()) {
        m_playlistMap[m_keyList[m_currentPlaylist]]->stop();
        if(m_debug)
            std::cout << "- Playlist stopped" << std::endl;
    } 
}

/*
 * \brief Update the playlist
 */
void MusicManager::update() {

    for(unsigned int i = 0; i < m_keyList.size(); i++)
        m_playlistMap[m_keyList[i]]->update();
}

/**
 * \brief Play the specified sound
 */
void MusicManager::playSound(std::string key) {
    m_soundMap[key]->play();
}

/*!
 * \brief return the current playlist
 * \return the good playlist
 */
Playlist * MusicManager::getPlaylist() {
    return m_playlistMap[m_keyList[m_currentPlaylist]];
}

/**
 * \brief return a playlist from the map
 * \param key the key to get the good playlist
 * \return the associated playlist
 */
Playlist * MusicManager::getPlaylist(std::string key) {
    return m_playlistMap[key];
}

/*!
 * \brief Find the index of the key in the map
 * \param key The current key
 * \return The index of the key
 */
int MusicManager::findIndex(std::string key) {

    for(unsigned int i = 0; i < m_keyList.size(); i++)
        if(m_keyList[i] == key) return i;
    return 0;
}