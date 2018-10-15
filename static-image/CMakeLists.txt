project(static-image)

cmake_minimum_required(VERSION 3.12)

find_package(Qt5Widgets)

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

# Agrego ej3/include a la lista de directorios de includes
include_directories(${PROJECT_SOURCE_DIR}/include)

qt5_wrap_ui(UIS_HEADERS
        ui/static.ui
)

message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

message("Headers generados: ${UIS_HEADERS}")

add_executable(static
  src/Static.cpp
  src/main.cpp
  ${UIS_HEADERS})

# Use the Widgets module from Qt 5.
target_link_libraries(static Qt5::Widgets)
