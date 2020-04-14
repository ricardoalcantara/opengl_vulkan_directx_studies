cmake_minimum_required(VERSION 3.0.0)
project(hw3d VERSION 0.1.0)

# https://cmake.org/cmake/help/v3.0/prop_gbl/USE_FOLDERS.html
# Use the FOLDER target property to organize targets into folders.
#
# If not set, CMake treats this property as OFF by default.
# CMake generators that are capable of organizing into a hierarchy of 
# folders use the values of the FOLDER target property to name those 
# folders. See also the documentation for the FOLDER target property.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 17)

include_directories(${WinSDK})

# Favor Size Or Speed
add_compile_options(/Ot) # Favor fast code
# Multi-processor Compilation
# add_compile_options(/MT)

# Floating Point Model
add_compile_options(/fp:fast)
# CharacterSet MultiByte
add_compile_options(/D_TEXT)
# Windows Flags
add_compile_options(/DWIN32 /D_WINDOWS)
# Other Flags
string(REPLACE "/MDd" "/MTd" ${CMAKE_CXX_FLAGS_DEBUG} "${CMAKE_CXX_FLAGS_DEBUG}")
string(REPLACE "/MD" "/MT" ${CMAKE_CXX_FLAGS_RELEASE} "${CMAKE_CXX_FLAGS_RELEASE}")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_WIN32_EXECUTABLE ON)
endif()

add_executable(${PROJECT_NAME} src/WinMain.cpp)

target_link_libraries(${PROJECT_NAME} ${WinSDK} d3d11)
