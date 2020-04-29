cmake_minimum_required(VERSION 3.7)
project(Drawing_a_triangle)


# file(GLOB VENDORS_SOURCES vendor/glad/src/glad.c)
file(GLOB PROJECT_HEADERS src/*.hpp)
file(GLOB PROJECT_SOURCES src/*.cpp)

source_group("Headers" FILES ${PROJECT_HEADERS})
# source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
# source_group("Vendors" FILES ${VENDORS_SOURCES})

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(${PROJECT_NAME} 
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ../common
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    # glm
    glfw
    Vulkan::Vulkan
)

###

file(GLOB VERTEX_SHADERS ${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.vert)
file(GLOB FRAGMENT_SHADERS ${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.frag)

add_shaders(${VERTEX_SHADERS})
add_shaders(${FRAGMENT_SHADERS})
