cmake_minimum_required(VERSION 3.0)

project (DeepTerrainRL)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Eigen 3
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Util module
AUX_SOURCE_DIRECTORY(util UTIL_SOURCES)
add_library(Util ${UTIL_SOURCES})

# Anim Module
AUX_SOURCE_DIRECTORY(anim ANIM_SOURCES)
add_library(Anim ${ANIM_SOURCES})

include_directories(${PROJECT_SOURCE_DIR})
