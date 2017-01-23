# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Project's name

project(Game CXX)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

# Set the compiler config
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(flags "-std=c++1z -stdlib=libc++ -m64 -Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(flags "/std:c++17 /W4 /WX /EHsc /ZI /MACHINE:X64")
endif()
  
if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${flags}")
endif()

# Find specific library
find_library(FREE_IMAGE freeImagePlus)

# Include subfolders with CMAKE files.
# SDL2
add_subdirectory("${CMAKE_SOURCE_DIR}/dependencies/lib/SDL2")
set(SDL_STATIC FALSE)

# The folders with the header files.
include_directories("${CMAKE_SOURCE_DIR}/dependencies/include")
include_directories(${SDL2_INCLUDE_DIR})


# Include recursively folders.
# file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
# add_executable(foo ${SRC_FILES})

add_executable(Game
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/dependencies/lib/glad.cpp
)

# Link a library
target_link_libraries(Game SDL2 freeImagePlus)

# Install
install(TARGETS Game RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/bin")

