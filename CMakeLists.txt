cmake_minimum_required(VERSION 3.24)
project(ShotgunKitty)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(engine)
include_directories(engine/include)

file(GLOB SRC src/*)
add_executable(ShotgunKitty ${SRC} engine/src/Widow.cpp engine/include/engine/Widow.h)
target_link_libraries(ShotgunKitty ShotgunKittyEngine)
