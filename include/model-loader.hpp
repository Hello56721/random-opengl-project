#ifndef B7857980_D91D_4395_92F9_845444BBE287
#define B7857980_D91D_4395_92F9_845444BBE287

#include <mesh.hpp>
#include <string_view>

namespace ModelLoader {
    // Load a model using assimp
    Mesh loadModel(std::string_view path);
}

#endif /* B7857980_D91D_4395_92F9_845444BBE287 */
