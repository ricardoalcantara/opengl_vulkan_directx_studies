cmake_minimum_required(VERSION 3.0)

project(GLAD)

include_directories(src/
                    include/)

add_library(${PROJECT_NAME} src/glad.c
                            include/glad/glad.h
                            include/KHR/khrplatform.h)
