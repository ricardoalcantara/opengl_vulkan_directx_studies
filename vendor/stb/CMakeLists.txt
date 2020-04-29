cmake_minimum_required(VERSION 3.0)

project(stb)

add_library(stb_image INTERFACE)
add_library(STB::STB_IMAGE ALIAS stb_image)

target_include_directories(stb_image INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)