find_path(
    ASSIMP_INCLUDE_DIR
    PATHS "${CMAKE_SOURCE_DIR}/libs/Assimp/include"
    NAMES "assimp/Importer.hpp" "assimp/scene.h" "assimp/postprocess.h"
)

find_library(
    ASSIMP_LIBRARY
    PATHS "${CMAKE_SOURCE_DIR}/libs/Assimp/lib" "${CMAKE_BINARY_DIR}"
    NAMES "assimp.lib" "libassimp.so" "libassimp.a" "libassimp.dll.a"
)

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("Assimp" DEFAULT_MSG ASSIMP_LIBRARY ASSIMP_INCLUDE_DIR)