cmake_minimum_required(VERSION 3.0)

project(VulkanTutorial)

set(CMAKE_CXX_STANDARD 11)

set(VENDOR "../vendor")
set(CMAKE_CXX_STANDARD 11)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${VENDOR}/glfw glfw)

set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)
set(GLM_ENABLE_CXX_11 ON CACHE BOOL "" FORCE)
add_subdirectory(${VENDOR}/glm glm)

find_package(Vulkan)

###### GLSLC
file(GLOB glslc-folders ${VULKAN_SDK}/bin/*)
find_program(GLSLC glslc HINTS ${glslc-folders})

function(add_shader SHADER OUTPUT)
    set(current-shader-path ${SHADER})
    set(current-output-path ${CMAKE_CURRENT_SOURCE_DIR}/shaders/${OUTPUT}.spv)
    add_custom_command(
        OUTPUT ${current-output-path}
        DEPENDS ${current-shader-path}
        COMMAND
            ${GLSLC}
            ${current-shader-path}
            -o ${current-output-path}
    )
    set_source_files_properties(${current-output-path} PROPERTIES GENERATED TRUE)
	target_sources(${PROJECT_NAME} PRIVATE ${current-output-path})
endfunction(add_shader)

function(add_shaders SHADERS)
    foreach(SHADER ${SHADERS})
        get_filename_component(SHADER_NAME ${SHADER} NAME)
        add_shader(${SHADER} ${SHADER_NAME})
    endforeach(SHADER)
endfunction(add_shaders)
###### GLSLC

add_subdirectory(Drawing_a_triangle)
