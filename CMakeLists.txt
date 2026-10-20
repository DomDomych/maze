cmake_minimum_required(VERSION 3.16)
project(maze LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(maze
    main.cpp
    cli/src/cli.cpp
)

target_include_directories(maze PRIVATE
    core/include
    cli/include
)
