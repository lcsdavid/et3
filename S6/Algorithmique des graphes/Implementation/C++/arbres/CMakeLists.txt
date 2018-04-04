cmake_minimum_required(VERSION 3.9)
project(arbres)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp
                 Arbre.cpp
                 ArbreBinaire.cpp
                 ArbreBinaireRecherche.cpp)

add_executable(arbres ${SOURCE_FILES})