# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Getting sources
FILE(GLOB_RECURSE SOURCE_FILES *)

message(STATUS ${SOURCE_FILES})

# Creating the executable target
ADD_EXECUTABLE(${TARGET_COMPILE} ${SOURCE_FILES})

MESSAGE(STATUS ${SFML_LIB})

# Linking all static libraries
TARGET_LINK_LIBRARIES(${TARGET_COMPILE}
        ${SFML_DEPENDENCIES}
        ${UNIX_DEPENDENCIES}
        ${WINDOWS_DEPENDENCIES})