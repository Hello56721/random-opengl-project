cmake_minimum_required(VERSION "3.16")

project("random-opengl-project")

# Use C++17
set(CMAKE_CXX_STANDARD 17)
# Where the package finders are
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Options
option(BUILD_SHARED_LIBS "Wether or not to build shared libraries." "true")
option(ENABLE_OPENGL_DEBUGGING "Wether or not to enable OpenGL debugging." "true")

# Configure the options
configure_file("cmake-configurations.hpp" "cmake-configurations.hpp")

# Find the libraries
find_package("GLFW")
find_package("GLAD")
find_package("GLM")

# Set the includes
include_directories("${GLFW_INCLUDE_DIR}" "${GLAD_INCLUDE_DIR}" "${GLM_INCLUDE_DIR}" "${CMAKE_SOURCE_DIR}/include" "${CMAKE_BINARY_DIR}")

# Set up GLAD
add_library("GLAD" "${GLAD_SOURCE_FILE}")
link_libraries("GLAD")

# Link GLFW
if (WIN32)
    link_libraries("${GLFW_LIBRARY}" "gdi32" "opengl32")
elseif(UNIX AND NOT APPLE)
    link_libraries("${GLFW_LIBRARY}" "GL" "X11" "pthread" "Xrandr" "dl")
elseif(APPLE)
    link_libraries("${GLFW_LIBRARY}")
endif()

# Turn on high warning levels
if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

add_executable("random-opengl-project")

add_subdirectory("src")
add_subdirectory("include")