cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(CHECKERS)


set(HEADERS_DIRECTORY "./inc")
include_directories(${HEADERS_DIRECTORY})

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(CHECKERS ${SOURCES})

set(SFML_STATIC_LIBRARIES TRUE) # TRUE (WINDOWS)

####################################################################################################################
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
    message(FATAL_ERROR "Rozpakuj biblioteke: SFM-2.5.1")
endif()
######################################################
set(SFML_DIR ./SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics REQUIRED)

include_directories(./SFML-2.5.1/include)
target_link_libraries(CHECKERS sfml-graphics)
####################################################################################################################
