#ifndef __RESOURCE_LOADER_HPP
#define __RESOURCE_LOADER_HPP

/// \brief Load all resources
void LoadAll();

/// \param base The base path
/// \param path The path
/// \param name The name
/// \return A concatenated string
std::string buildPath(std::string const& base,
                      std::string const& path,
                      std::string const& name);

/// \brief Load a texture
/// \param key The key
/// \param path The path
void LoadTexture(std::string const& key, std::string const& path);

/// \brief Load a music
/// \param key The key
/// \param path The path
void LoadMusic(std::string const& key, std::string const& path);

#endif // __RESOURCE_LOADER_HPP