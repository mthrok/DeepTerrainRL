cmake_minimum_required(VERSION 3.0)

project (DeepTerrainRL)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#OpenGL
find_package(OpenGL REQUIRED)

# GLEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIR})

# GLUT
find_package(GLUT REQUIRED)

# GLOG
find_package(GLOG REQUIRED)

# Boost
find_package(Boost COMPONENTS system REQUIRED)

# HDF5
find_package(HDF5 REQUIRED)

# Eigen 3
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# CBLAS or vecLib
if(APPLE)
  find_package(VECLIB)
  include_directories(${vecLib_INCLUDE_DIR})
endif()

# JSONCPP
SET(JSON_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/external/jsoncpp/include")
SET(JSON_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/external/jsoncpp/build/release/src/lib_json/libjsoncpp.a")

# Caffe
SET(CAFFE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/external/caffe/src"
		      "${PROJECT_SOURCE_DIR}/external/caffe/include"
		      "${PROJECT_SOURCE_DIR}/external/caffe/build/src")
SET(CAFFE_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/external/caffe/build/lib/libcaffe.so")

# Bullet
SET(BULLET_ROOT "${PROJECT_SOURCE_DIR}/external/Bullet")
SET(BULLET_INCLUDE_DIR "${BULLET_ROOT}/src")
SET(BULLET_LIBRARY_PATH "${BULLET_ROOT}/build/src/LinearMath/libLinearMath.a"
			"${BULLET_ROOT}/build/src/BulletDynamics/libBulletDynamics.a"
			"${BULLET_ROOT}/build/src/BulletCollision/libBulletCollision.a")

# Libraries
SET(DEPENDENCIES ${HDF5_C_LIBRARIES} ${Boost_LIBRARIES} ${JSON_LIBRARY_PATH} ${BULLET_LIBRARY_PATH} ${CAFFE_LIBRARY_PATH} ${GLOG_LIBRARIES})

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


################################################################################
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${JSON_INCLUDE_DIR})

# Util module
AUX_SOURCE_DIRECTORY(util UTIL_SOURCES)
add_library(Util ${UTIL_SOURCES})

################################################################################
include_directories(${BULLET_INCLUDE_DIR} ${CAFFE_INCLUDE_DIR})

# Anim Module
AUX_SOURCE_DIRECTORY(anim ANIM_SOURCES)
add_library(Anim ${ANIM_SOURCES})

# Learning Module
AUX_SOURCE_DIRECTORY(learning LEARNING_SOURCES)
add_library(Learning ${LEARNING_SOURCES})

# Sim Module
AUX_SOURCE_DIRECTORY(sim SIM_SOURCES)
add_library(Sim ${SIM_SOURCES})

# Render Module
AUX_SOURCE_DIRECTORY(render RENDER_SOURCES)
add_library(Render ${RENDER_SOURCES})

################################################################################
# Scenario Module
AUX_SOURCE_DIRECTORY(scenarios SCENARIO_SOURCES)
add_library(Scenario ${SCENARIO_SOURCES})

################################################################################
# Build Optimizer
AUX_SOURCE_DIRECTORY(optimizer/scenarios OPT_SCENARIO_SOURCES)
add_library(OptScenario ${OPT_SCENARIO_SOURCES})


add_executable(Optimizer optimizer/Main.cpp)
target_link_libraries(Optimizer ${DEPENDENCIES} Util Scenario Sim Learning Render Anim OptScenario)

################################################################################
# Build Visualizer
add_executable(Visualizer Main.cpp)
target_link_libraries(Visualizer ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${DEPENDENCIES} ${GLUT_LIBRARY} Util Scenario Sim Learning Render Anim OptScenario)
