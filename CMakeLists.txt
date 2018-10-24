project(window)

cmake_minimum_required(VERSION 3.12)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(SDL2 REQUIRED)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

#message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

file(GLOB SOURCE
        src/*.cpp
        src/*.h
        )

message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/SdlWindow.cpp
        src/SdlWindow.h
        src/SdlException.cpp
        src/SdlException.h src/SdlTexture.cpp src/SdlTexture.h src/Area.cpp src/Area.h
        $(SOURCE))

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

