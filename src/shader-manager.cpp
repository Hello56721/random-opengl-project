#include <shader-manager.hpp>

#include <glad/glad.h>
#include <opengl-debug.hpp>

ShaderManager::ShaderManager() {
    
}

ShaderManager& ShaderManager::getInstance() {
    static ShaderManager instance;
    return instance;
}

ShaderManager::~ShaderManager() {
    for (std::vector<Shader>::iterator i = shaders.begin(); i != shaders.end(); i++) {
        glCall(glDeleteShader, i->program);
    }
}