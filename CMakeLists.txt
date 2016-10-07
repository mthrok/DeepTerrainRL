cmake_minimum_required(VERSION 3.0.2)

project (DeepTerrainRL)

# Additional module finders
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/module")

#OpenGL
find_package(OpenGL REQUIRED)

# GLEW
find_package(GLEW REQUIRED)

# GLUT
find_package(GLUT REQUIRED)

# GLOG
find_package(Glog REQUIRED)

# Boost
find_package(Boost COMPONENTS system REQUIRED)

# HDF5
find_package(HDF5 REQUIRED)

# Eigen 3
find_package(Eigen3 REQUIRED)

# CBLAS or vecLib
if(APPLE)
  find_package(VECLIB)
  include_directories(${vecLib_INCLUDE_DIR})
endif()

# Include function to build dependency at configuration time
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/cmake/builder")

# Build Bullet Phyisics
SET(BULLET_ROOT "${CMAKE_SOURCE_DIR}/external/bullet")
BUILD_EXTERNAL_PROJECT(
  bullet
  "${BULLET_ROOT}"
  "https://github.com/bulletphysics/bullet3"
  -DBUILD_BULLET2_DEMOS:BOOL=OFF
  -DUSE_DX11:BOOL=OFF
  -DUSE_GLUT:BOOL=OFF
  -DUSE_GRAPHICAL_BENCHMARK:BOOL=OFF
  -DBUILD_EXTRAS:BOOL=OFF
  -DBUILD_UNIT_TESTS:BOOL=OFF
  -DUSE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=ON
  #-DBUILD_SHARED_LIBS:BOOL=OFF  # this is broken in Visual Studio
  # Add -fPIC on Linux so we can actually link into a shared lib later
  "-DCMAKE_CXX_FLAGS=${CMAKE_SHARED_LIBRARY_CXX_FLAGS}"
  "-DCMAKE_C_FLAGS=${CMAKE_SHARED_LIBRARY_C_FLAGS}"
  -DINSTALL_LIBS:BOOL=ON
  -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
  #-DPKGCONFIG_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
  #-DINCLUDE_INSTALL_DIR:PATH=${CMAKE_INSTALL_PREFIX}/include/
  #-DLIB_DESTINATION:PATH=${CMAKE_INSTALL_PREFIX}/lib/
  )
find_package(Bullet REQUIRED)

# Build JsonCPP
SET(JSONCPP_ROOT "${CMAKE_SOURCE_DIR}/external/jsoncpp")
BUILD_EXTERNAL_PROJECT(
  jsoncpp
  "${JSONCPP_ROOT}"
  "https://github.com/open-source-parsers/jsoncpp"
  -DCMAKE_BUILD_TYPE=release
  -DBUILD_STATIC_LIBS=ON
  -DBUILD_SHARED_LIBS=OFF
  )
find_package(Jsoncpp REQUIRED)


# Caffe
SET(CAFFE_DIR "${PROJECT_SOURCE_DIR}/external/caffe")
BUILD_EXTERNAL_PROJECT(
  caffe
  "${CAFFE_DIR}"
  "https://github.com/BVLC/caffe"
  -DCPU_ONLY:BOOL=ON
  )
SET(Caffe_DIR "${PROJECT_SOURCE_DIR}/external/caffe/src/caffe-build/install/")
find_package(Caffe REQUIRED)

# Source dir
SET(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# Include
include_directories(${GLEW_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR} ${SOURCE_DIR} ${JSONCPP_INCLUDE_DIRS} ${BULLET_INCLUDE_DIR} ${Caffe_INCLUDE_DIR})

# Libraries
SET(DEPENDENCIES ${HDF5_C_LIBRARIES} ${Boost_LIBRARIES} ${JSONCPP_LIBRARIES} ${BULLET_LIBRARIES} ${Caffe_LIBS} ${GLOG_LIBRARIES})

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

################################################################################
# Util module
AUX_SOURCE_DIRECTORY(${SOURCE_DIR}/util UTIL_SOURCES)
add_library(Util ${UTIL_SOURCES})

# Anim Module
AUX_SOURCE_DIRECTORY(${SOURCE_DIR}/anim ANIM_SOURCES)
add_library(Anim ${ANIM_SOURCES})

# Learning Module
add_definitions(-DCPU_ONLY)
AUX_SOURCE_DIRECTORY(${SOURCE_DIR}/learning LEARNING_SOURCES)
add_library(Learning ${LEARNING_SOURCES})

# Sim Module
AUX_SOURCE_DIRECTORY(${SOURCE_DIR}/sim SIM_SOURCES)
add_library(Sim ${SIM_SOURCES})

# Render Module
AUX_SOURCE_DIRECTORY(${SOURCE_DIR}/render RENDER_SOURCES)
add_library(Render ${RENDER_SOURCES})

# Scenario Module
AUX_SOURCE_DIRECTORY(${SOURCE_DIR}/scenarios SCENARIO_SOURCES)
add_library(Scenario ${SCENARIO_SOURCES})

################################################################################
# Build Optimizer
AUX_SOURCE_DIRECTORY(${SOURCE_DIR}/optimizer/scenarios OPT_SCENARIO_SOURCES)
add_library(OptScenario ${OPT_SCENARIO_SOURCES})


add_executable(Optimizer ${SOURCE_DIR}/optimizer/Main.cpp)
target_link_libraries(Optimizer ${DEPENDENCIES} Util Scenario Sim Learning Render Anim OptScenario)

################################################################################
# Build Visualizer
add_executable(Visualizer ${SOURCE_DIR}/Main.cpp)
target_link_libraries(Visualizer ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${DEPENDENCIES} ${GLUT_LIBRARY} Util Scenario Sim Learning Render Anim OptScenario)
