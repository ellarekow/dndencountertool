cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 3.21)
#project(assignment_1_03 C)
#SET(CURSES_USE_NCURSES TRUE)
#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})
#message (STATUS ${CURSES_LIBRARIES} ${CURSES_INCLUDE_DIR})
#add_executable(assignment_1_03 main.c terrain.c terrain.h travel.c travel.h util.c util.h npc.c npc.h heap.h heap.c)
#
#target_link_libraries(assignment_1_03 ncurses)

project(main)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(main ability.cpp ability.h character.h character.cpp dice.cpp dice.h encounter.cpp encounter.h io.cpp io.h NPC.cpp NPC.h PC.cpp PC.h session.cpp session.h)
target_link_libraries(main ncurses)
target_link_libraries(main tinfo)