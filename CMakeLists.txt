#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_STANDARD 17)
# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(Robocup2018Simulator)

# Set version information in a config.h file
set(Robocup2018Simulator_VERSION_MAJOR 1)
set(Robocup2018Simulator_VERSION_MINOR 0)

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}" src/spdlog/ src/inih/)

# Define sources and executable
file(GLOB_RECURSE SOURCES src/*.cpp)
set(EXECUTABLE_NAME "Robocup2018Simulator")
add_executable(${EXECUTABLE_NAME} ${SOURCES} src/Utils.h src/Utils.cpp src/sketch.h  src/Subsystems/Tiles/Tile.cpp src/Subsystems/Tiles/Tile.h src/Subsystems/Tiles/Wall.cpp src/Subsystems/Tiles/Wall.h src/EctoSettings.cpp src/EctoSettings.h src/Subsystems/Tiles/DrawableTile.cpp src/Subsystems/Tiles/DrawableTile.h src/Subsystems/Tiles/TileGrid.cpp src/Subsystems/Tiles/TileGrid.h src/Subsystems/Tiles/DrawableTileGrid.cpp src/Subsystems/Tiles/DrawableTileGrid.h src/Subsystems/Robot/SensorBase.h  src/Subsystems/Robot/MotorBase.h src/Subsystems/Tiles/TileTypes.h src/Subsystems/Tiles/WallTypes.h src/Subsystems/Robot/RobotUtils.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

target_link_libraries(${EXECUTABLE_NAME} pthread)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${Robocup2018Simulator_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Robocup2018Simulator_VERSION_MINOR}")
include(CPack)