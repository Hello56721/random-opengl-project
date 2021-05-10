find_path(
    GLAD_INCLUDE_DIR
    NAMES "glad/glad.h"
    PATHS "${CMAKE_SOURCE_DIR}/libs/GLAD/include"
)

find_file(
    GLAD_SOURCE_FILE
    NAMES "glad.c"
    PATHS "${CMAKE_SOURCE_DIR}/libs/GLAD/src"
)

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("GLAD" DEFAULT_MSG GLAD_SOURCE_FILE GLAD_INCLUDE_DIR)