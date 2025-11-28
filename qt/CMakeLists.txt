cmake_minimum_required(VERSION 3.16)
project(LevelManagerQt LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(level_manager
    main.cpp
    LevelManager.cpp
    LevelLoader.cpp
    LevelTypes.cpp)

target_include_directories(level_manager PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(level_manager PRIVATE Qt6::Core)
