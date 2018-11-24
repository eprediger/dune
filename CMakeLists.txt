cmake_minimum_required(VERSION 3.12)
project(dune)

set(CMAKE_CXX_STANDARD 11)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -ggdb -O0 -pthread")
else()
	set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -ggdb -O0 -pthread")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(SDL2 REQUIRED)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
FIND_PACKAGE( yaml-cpp REQUIRED)
INCLUDE_DIRECTORIES(${YAML_CPP_INCLUDE_DIRS})

# Agregando esto se evita usar paths relativos en los include
INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# Reemplazar por TARGET_INCLUDE_DIRECTORIES al tener cliente/servidor


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	SET(GCC_COVERAGE_LINK_FLAGS "-Wl -lSDL2_ttf -lSDL2_mixer -lSDL2")
else()
	SET(GCC_COVERAGE_LINK_FLAGS "-Wl,--no-as-needed -lSDL2_ttf -lSDL2_mixer -lSDL2")
endif()
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )


file(GLOB_RECURSE SOURCE
		src/*.cpp
		src/*.h
        )

add_executable(${PROJECT_NAME}
               ${SOURCE} src/View/TimerView.cpp src/View/TimerView.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${YAML_CPP_LIBRARIES})
