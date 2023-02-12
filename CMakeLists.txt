cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(WARCABY)


set(HEADERS_DIRECTORY "./inc")
include_directories(${HEADERS_DIRECTORY})

add_executable(WARCABY src/Main.cpp src/m_loop.cpp src/font_menu.cpp src/pola_menu.cpp src/tekst_menu.cpp src/txt_menu.cpp src/screen.cpp src/AI_gracz.cpp src/Register.cpp)

set(SFML_STATIC_LIBRARIES FALSE) # TRUE

####################################################################################################################
set(SFML_DIR SFML/)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

include_directories(SFML/include)
target_link_libraries(WARCABY sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
####################################################################################################################

