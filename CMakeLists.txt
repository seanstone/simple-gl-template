cmake_minimum_required (VERSION 2.6)

project(SimpleGLTemplate)

# Include headers
include_directories(include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
link_directories(${CMAKE_BINARY_DIR}/..)

# setup some flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -ffast-math -std=c++11 -Wall -W -pedantic -Wextra")

# Sources
file(GLOB SOURCES "src/*.cpp" "src/*.c")
add_executable(SimpleGLTemplate ${SOURCES})

if(WIN32)
	target_link_libraries(SimpleGLTemplate glfw3 opengl32)
else()
	target_link_libraries(SimpleGLTemplate glfw GL)
endif()
