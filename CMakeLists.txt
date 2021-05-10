cmake_minimum_required(VERSION "3.16")

project("random-opengl-project")

# Turn on high warning levels
if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall")
endif()

add_executable("random-opengl-project")

add_subdirectory("src")