cmake_minimum_required(VERSION 3.0)

project (DeepTerrainRL)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# GLEW
find_package(GLEW REQUIRED)
MESSAGE(${GLEW_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})

# Eigen 3
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# CBLAS or vecLib
if(APPLE)
  find_package(VECLIB)
  include_directories(${vecLib_INCLUDE_DIR})
endif()

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Util module
AUX_SOURCE_DIRECTORY(util UTIL_SOURCES)
add_library(Util ${UTIL_SOURCES})

# Anim Module
AUX_SOURCE_DIRECTORY(anim ANIM_SOURCES)
add_library(Anim ${ANIM_SOURCES})

# Learning Module
AUX_SOURCE_DIRECTORY(learning LEARNING_SOURCES)
add_library(Learning ${LEARNING_SOURCES})

# Sim Module
AUX_SOURCE_DIRECTORY(sim SIM_SOURCES)
add_library(Sim ${SIM_SOURCES})

include_directories("${PROJECT_SOURCE_DIR}/external/Bullet/src")

include_directories("${PROJECT_SOURCE_DIR}/external/caffe/src")
include_directories("${PROJECT_SOURCE_DIR}/external/caffe/include")
include_directories("${PROJECT_SOURCE_DIR}/external/caffe/build/src")


include_directories(${PROJECT_SOURCE_DIR})
