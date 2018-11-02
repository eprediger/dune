cmake_minimum_required(VERSION 3.12)
project(dune)

set(CMAKE_CXX_STANDARD 11)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -pthread")
else()
	set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -pthread")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(SDL2 REQUIRED)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	SET(GCC_COVERAGE_LINK_FLAGS "-Wl -lSDL2 -lSDL2_mixer")
else()
	SET(GCC_COVERAGE_LINK_FLAGS "-Wl,--no-as-needed -lSDL2 -lSDL2_mixer")
endif()
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

file(GLOB SOURCE
        src/*.cpp
        src/*.h
        src/*/*.cpp
        src/*/*.h
        )

message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

add_executable(${PROJECT_NAME}
               ${SOURCE})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES})
