cmake_minimum_required(VERSION 3.24)
project(TileMapEditor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

file(GLOB SRC src/*)
add_executable(TileMapEditor ${SRC})
target_link_libraries(TileMapEditor
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

