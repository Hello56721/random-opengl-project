find_path(
    GLM_INCLUDE_DIR
    NAMES "glm/glm.hpp" "glm/gtc/matrix_transform.hpp" "glm/gtc/type_ptr.hpp"
    PATHS "${CMAKE_SOURCE_DIR}/libs/GLM"
    DOC "Absolute path to GLM's include directory"
)

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("GLM" DEFAULT_MSG GLM_INCLUDE_DIR)