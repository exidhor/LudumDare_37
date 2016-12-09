# Ludum Dare 37
# LD Project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Getting sources
FILE(GLOB_RECURSE SOURCE_FILES *)

# Creating the executable target
ADD_EXECUTABLE(${TARGET_COMPILE} ${SOURCE_FILES})

# Platform specific linkage
IF(PLATFORM_WINDOWS)
    # Linking all static libraries for windows
    TARGET_LINK_LIBRARIES(${TARGET_COMPILE}
            ${SFML_DEPENDENCIES}
            ${WINDOWS_DEPENDENCIES})

ELSEIF(PLATEFROM_UNIX)
    # Linking all static libraries for windows
    TARGET_LINK_LIBRARIES(${TARGET_COMPILE}
            ${SFML_DEPENDENCIES}
            ${UNIX_DEPENDENCIES})

ENDIF()
