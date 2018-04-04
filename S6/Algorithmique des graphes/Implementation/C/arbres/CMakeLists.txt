cmake_minimum_required(VERSION 3.9)
project(arbres)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8 -fextended-identifiers")

message("Flags: ${CMAKE_C_FLAGS}")

set(SOURCE_FILES main.c arbre.c)

add_executable(arbres ${SOURCE_FILES})