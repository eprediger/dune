cmake_minimum_required(VERSION 3.12)
project(map_maker)

set(CMAKE_CXX_STANDARD 11)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -ggdb -O0 -pthread")
else()
	set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -ggdb -O0 -pthread")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FIND_PACKAGE( yaml-cpp REQUIRED)
INCLUDE_DIRECTORIES(${YAML_CPP_INCLUDE_DIRS})

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	SET(GCC_COVERAGE_LINK_FLAGS "-Wl")
else()
	SET(GCC_COVERAGE_LINK_FLAGS "-Wl,--no-as-needed")
endif()
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

file(GLOB SOURCE
		src/*.cpp
		src/*.h
		src/*/*.cpp
		src/*/*.h
		src/*/*/*.cpp
		src/*/*/*.h
		src/*/*/*/*.cpp
		src/*/*/*/*.h
        )

add_executable(${PROJECT_NAME}
               ${SOURCE})

INCLUDE(FindPkgConfig)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${YAML_CPP_LIBRARIES})
