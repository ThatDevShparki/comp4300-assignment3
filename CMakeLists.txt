cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wno-unused-result -pedantic-errors")

project(comp4300_assignment3
        LANGUAGES CXX
        VERSION 0.1.0
)


# install dependencies
include(FetchContent)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


# create executable
set(exec_name comp4300_assignment3)
set(src_files
        src/main.cpp
        src/Action.cpp
        src/Animation.cpp
        src/Assets.cpp
        src/Entity.cpp
        src/EntityManager.cpp
        src/GameEngine.cpp
        src/Physics.cpp
        src/Scene.cpp
        src/Scene_Menu.cpp
        src/Scene_Play.cpp
        src/Vec2.cpp
)
add_executable(${exec_name} ${src_files})

target_link_libraries(${exec_name} PRIVATE sfml-graphics)
target_compile_features(${exec_name} PRIVATE cxx_std_17)

include_directories(include)

install(TARGETS ${exec_name})


# move assets over
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})