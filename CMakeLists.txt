cmake_minimum_required(VERSION 3.16)
project(Licznik_template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Licznik_template
   src/main.cpp
    src/HallSensorAdapter.cpp
    src/NoFilter.cpp
    src/MovingAverageFilter.cpp
    src/Display.cpp
    src/Logger.cpp
    src/IdleState.cpp
    src/RidingState.cpp
    src/PausedState.cpp
    src/BikeComputer.cpp
    src/AppController.cpp
)

target_include_directories(Licznik_template PRIVATE include)