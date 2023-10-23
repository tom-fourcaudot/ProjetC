cmake_minimum_required(VERSION 3.26)
project(ProjetC C)

set(CMAKE_C_STANDARD 23)

add_executable(ProjetC main.c
        Rope/Rope.h
        Rope/Node.h
        Rope/Node.c
        Rope/Rope.c
        Rope/String.c
        Rope/String.h
)

target_link_libraries(ProjetC PRIVATE m)
