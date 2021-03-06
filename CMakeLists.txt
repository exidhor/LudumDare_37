# Ludum Dare 37
# LD Project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30

# CMake configuration
PROJECT(LudumDare)

# The 3.1 is really needed
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Compiler
# Setting standard
SET(CMAKE_CXX_STANDARD 11)

# Getting all needed informations
IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # Using GNU GCC
    SET(COMPILER_GCC 1)
    ADD_DEFINITIONS(-D COMPILER_GCC)
    MESSAGE(STATUS "Compiler : GCC")

    # For GCC, setting flags
    SET(CXX_RELEASE_FLAGS "-Wall -O3")
    SET(CXX_DEBUG_FLAGS   "-Wall -Wextra -g")

ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # using Visual Studio C++
    SET(COMPILER_MVSC 1)
    MESSAGE(STATUS "Compiler : MSVC")
    ADD_DEFINITIONS(-D COMPILER_MVSC)

    # No flags for MVSC

ENDIF()

# Checking plateform
IF(WIN32)
    # Windows operating system
    SET(PLATFORM_WINDOWS 1)
    ADD_DEFINITIONS(-D PLATFORM_WINDOWS)
    MESSAGE(STATUS "Platform : Windows")

ELSEIF(UNIX)
    # Unix operating system
    SET(PLATFORM_UNIX 1)
    ADD_DEFINITIONS(-D PLATFORM_UNIX)
    MESSAGE(STATUS "Platform : Unix")

ELSE()
    # Not supported
    SET(PLATFORM_NOT_SUPORTED 0)
    ADD_DEFINITIONS(-D PLATFORM_NOT_SUPORTED)
    MESSAGE(FATAL_ERROR "This plateform is currently not supported")

ENDIF()

# Checking for CMake config
IF(NOT EXISTS ${CMAKE_SOURCE_DIR}/CMakeConfig.cmake)
    # Warning user
    MESSAGE(STATUS "Unable to find CMakeConfig.cmake")
    MESSAGE(STATUS "Creating CMakeConfig.cmake")

    # Creating the config file
    FILE(WRITE ${CMAKE_SOURCE_DIR}/CMakeConfig.cmake
            "# Ludum Dare 37"
            "\n# Game Engine project"
            "\n# Author : Aredhele, Exidhor"
            "\n# Date   : 2016-11-30"
            "\n\n# Path to SFML"
            "\nSET(SFML_PATH <PATH>)"
            "\n\n# List of all debug libs"
            "\nSET(SFML_LIB_DEBUG \"\")"
            "\n\n# List of all release libs"
            "\nSET(SFML_LIB_RELEASE \"\")")

    # Asking to fill the configuration
    MESSAGE(WARNING "Please set the cmake config")

ENDIF()

# Including SFML dependencies
INCLUDE(${CMAKE_SOURCE_DIR}/CMakeConfig.cmake)

# Setting compiler depending the mode
IF(CMAKE_BUILD_TYPE MATCHES Debug)
    # Debug mode
    ADD_DEFINITIONS(-D LD_DEBUG=1)
    MESSAGE(STATUS "Compilation mode : Debug")

    # Setting flags
    IF(COMPILER_GCC)
        # Only for GCC
        set(CMAKE_CXX_FLAGS_DEBUG ${CXX_DEBUG_FLAGS} CACHE STRING "DBG" FORCE)
    ENDIF()

    # Setting SFML dependencies
    SET(SFML_DEPENDENCIES ${SFML_LIB_DEBUG})

ELSEIF(CMAKE_BUILD_TYPE MATCHES Release)
    # Release mode
    ADD_DEFINITIONS(-D LD_DEBUG=0)
    MESSAGE(STATUS "Compilation mode : Release")

    # Setting flags
    IF(COMPILER_GCC)
        # Only for GCC
        set(CMAKE_CXX_FLAGS_DEBUG ${CXX_RELEASE_FLAGS} CACHE STRING "REL" FORCE)
    ENDIF()

    # Setting SFML dependencies
    SET(SFML_DEPENDENCIES ${SFML_LIB_RELEASE})

ELSE()
    # No mode
    MESSAGE(FATAL_ERROR "No build type")

ENDIF()

# Setting project properties
INCLUDE_DIRECTORIES(
        ${SFML_PATH}/include
        ${CMAKE_SOURCE_DIR}/Header)

# Setting output path
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin")

# Setting os-specific dependencies
SET(WIN32_DEPENDENCIES "")
SET(UNIX_DEPENDENCIES  "")

# Setting custom targets
SET(TARGET_COMPILE "LudumDare")

# Adding project dir
ADD_SUBDIRECTORY(Source)