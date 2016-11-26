cmake_minimum_required(VERSION 3.5)
project(reviiyot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES include/Card.h include/Deck.h include/Game.h include/Hand.h include/main.h include/Player.h
        src/reviiyot.cpp src/Cards/FigureCard.cpp src/Cards/Card.cpp src/Cards/NumericCard.cpp src/Deck.cpp src/Cards/CardRequest.cpp include/CardRequest.h src/Game.cpp)
add_executable(reviiyot ${SOURCE_FILES})