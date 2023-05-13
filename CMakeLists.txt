cmake_minimum_required(VERSION 3.23)
project(cli_rpg
        DESCRIPTION "Basic CLI RPG game"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/player.cpp

        include/mage.h
        include/player.h
        include/priest.h
        include/warrior.h)

target_include_directories(${PROJECT_NAME} PRIVATE include)