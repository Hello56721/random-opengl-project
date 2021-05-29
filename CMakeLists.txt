cmake_minimum_required(VERSION "3.16")

project("random-opengl-project")

# Use C++17
set(CMAKE_CXX_STANDARD 17)
# Where the package finders are
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Options
option(BUILD_SHARED_LIBS "Wether or not to build shared libraries." "true")
option(ENABLE_OPENGL_DEBUGGING "Wether or not to enable OpenGL debugging." "true")
option(GENERATE_DEBUG_INFORMATION "Whether or not to generate debug information" "false)")

# Configure the options
configure_file("cmake-configurations.hpp" "cmake-configurations.hpp")

# Find the libraries
find_package("GLFW")
find_package("GLAD")
find_package("GLM")
find_package("Assimp")
find_package("STB")

# Set the includes
include_directories(
    "${GLFW_INCLUDE_DIR}" 
    "${GLAD_INCLUDE_DIR}" 
    "${GLM_INCLUDE_DIR}"
    "${ASSIMP_INCLUDE_DIR}"
    "${STB_INCLUDE_DIR}"
    "${CMAKE_SOURCE_DIR}/include" 
    "${CMAKE_BINARY_DIR}"
)

# Set up GLAD
add_library("GLAD" "${GLAD_SOURCE_FILE}")
if (BUILD_SHARED_LIBS)
    target_compile_definitions("GLAD" PUBLIC "GLAD_GLAPI_EXPORT" PRIVATE "GLAD_GLAPI_EXPORT_BUILD")
endif()
link_libraries("GLAD")

# Set up STB
add_library("STB" STATIC "src/stb_image.c")
link_libraries("STB")

# Link GLFW
if (WIN32)
    link_libraries("${GLFW_LIBRARY}" "${ASSIMP_LIBRARY}" "gdi32" "opengl32")
elseif(UNIX AND NOT APPLE)
    link_libraries("${GLFW_LIBRARY}" "${ASSIMP_LIBRARY}" "GL" "X11" "pthread" "Xrandr" "dl")
elseif(APPLE)
    link_libraries("${GLFW_LIBRARY}" "${ASSIMP_LIBRARY}")
endif()

# Turn on high warning levels
if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

# Turn on debug informations
if (MSVC)
    if (GENERATE_DEBUG_INFORMATION)
        add_compile_options("/DEBUG")
        add_link_options("/DEBUG")
    endif()
else()
    if (GENERATE_DEBUG_INFORMATION)
        add_compile_options("-g3")
        add_link_options("-g3")
    endif()
endif()

add_executable("random-opengl-project")

add_subdirectory("src")
add_subdirectory("include")