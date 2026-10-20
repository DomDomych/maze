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

include(CTest)
if(BUILD_TESTING)
    find_package(GTest CONFIG QUIET)
    if(NOT GTest_FOUND)
        include(FetchContent)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_Declare(googletest
            URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        )
        FetchContent_MakeAvailable(googletest)
    endif()

    add_executable(maze_tests
        tests/main_test.cpp
        tests/unit/grid_test.cpp
        tests/unit/generation_test.cpp
        tests/unit/pathfinding_test.cpp
        tests/unit/rendering_test.cpp
        tests/integration/maze_workflow_test.cpp
    )
    target_include_directories(maze_tests PRIVATE core/include cli/include)
    target_link_libraries(maze_tests PRIVATE GTest::gtest)

    include(GoogleTest)
    gtest_discover_tests(maze_tests)
endif()
