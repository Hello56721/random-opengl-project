#include <texture-manager.hpp>

#include <opengl-debug.hpp>
#include <glad/glad.h>

TextureManager::TextureManager() {
    
}

TextureManager* TextureManager::getInstance() {
    static TextureManager* textureManager = new TextureManager();
    return textureManager;
}

TextureManager::~TextureManager() {
    for (std::vector<Texture>::iterator i = textures.begin(); i != textures.end(); i++) {
        glCall(glDeleteTextures, 1, &(i->texture));
    }
}