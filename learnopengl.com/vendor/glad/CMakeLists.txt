cmake_minimum_required(VERSION 3.0)

project(GLAD)

add_library(${PROJECT_NAME} src/glad.c
                            include/glad/glad.h
                            include/KHR/khrplatform.h)

target_include_directories(${PROJECT_NAME}
PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)