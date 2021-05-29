find_path(
    GLFW_INCLUDE_DIR
    NAMES "GLFW/glfw3.h"
    DOC "Absolute path to GLFW'is include directory"
    PATHS "${CMAKE_SOURCE_DIR}/libs/GLFW/include"
)

find_library(
    GLFW_LIBRARY
    NAMES "libglfw3.a" "libglfw3dll.a" "libglfw.so" "glfw3.lib" "glfw3dll.lib"
    DOC "Absolute path to GLFW's library"
    PATHS "${CMAKE_SOURCE_DIR}/libs/GLFW/lib" "${CMAKE_SOURCE_DIR}/libs/GLFW/src" "${CMAKE_SOURCE_DIR}/libs/GLFW/build/src" 
          "${CMAKE_BINARY_DIR}"
)

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("GLFW" DEFAULT_MSG GLFW_LIBRARY GLFW_INCLUDE_DIR)