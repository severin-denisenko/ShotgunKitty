cmake_minimum_required(VERSION 3.24)
project(ShotgunKittyEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SRC src/*)
file(GLOB INCLUDE include/*)
include_directories(include)

add_library(ShotgunKittyEngine ${SRC} ${INCLUDE})
target_link_libraries(ShotgunKittyEngine ${SDL2_LIBRARIES} SDL2_Image)
