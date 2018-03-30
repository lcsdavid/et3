cmake_minimum_required(VERSION 3.9)
project(Arbres)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES
        arbres/main.cpp
        arbres/Arbre.cpp)

add_executable(AAA ${SOURCE_FILES})
target_link_libraries(Arbres)