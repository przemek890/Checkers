cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
add_definitions(-DMY_DEFINE="${CMAKE_SOURCE_DIR}/bin/")


get_filename_component(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
set(PROJECT_ROOT_DIR "CHECKERS")
project(${PROJECT_ROOT_DIR})


set(HEADERS_DIRECTORY "./inc")
include_directories(${HEADERS_DIRECTORY})

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_ROOT_DIR} ${SOURCES})

set(SFML_DIR ./SFML-2.6.1/lib/cmake/SFML)

#######################################################
if(APPLE)
    set(SFML_STATIC_LIBRARIES FALSE)
elseif(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/lib/cmake/SFML")
        message(FATAL_ERROR "Rozpakuj biblioteke: SFM-2.6.1")
        include_directories(./SFML-2.6.1/include)
    endif()
endif()
######################################################
find_package(SFML COMPONENTS graphics REQUIRED)
target_link_libraries(${PROJECT_ROOT_DIR} sfml-graphics)
