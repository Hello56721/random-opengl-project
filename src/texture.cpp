#include <texture.hpp>

#include <opengl-debug.hpp>
#include <glad/glad.h>
#include <cstddef>
#include <stb_image.h>
#include <iostream>
#include <texture-manager.hpp>

using byte = unsigned char;

Texture::Texture(): texture(0) {
    
}

Texture::Texture(std::string_view path) {
    glCall(glGenTextures, 1, &texture);
    glCall(glBindTexture, GL_TEXTURE_2D, texture);
    
    int width, height, nrChannels;
    byte* data = stbi_load(path.data(), &width, &height, &nrChannels, 0);
    // Check if the data is valid or not
    if (data == nullptr) {
        std::cerr << "[ERROR]: Could not find or load " << path << std::endl;
        texture = 0;
        return;
    }
    
    // Determine the format
    unsigned int format;
    switch (nrChannels) {
    case 1:
        format = GL_RED;
        break;
    case 2:
        format = GL_RG;
        break;
    case 3:
        format = GL_RGB;
        break;
    case 4:
        format = GL_RGBA;
        break;
    }
    
    // Put the data into the texture
    glCall(glTexImage2D, GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glCall(glGenerateMipmap, GL_TEXTURE_2D);
    
    // Free the data
    stbi_image_free(data);
    
    // Add it to the thing so that we all know
    TextureManager* textureManager = TextureManager::getInstance();
    textureManager->textures.push_back(*this);
}

void Texture::bind() {
    glCall(glBindTexture, GL_TEXTURE_2D, texture);
}

void Texture::unbind() {
    glCall(glBindTexture, GL_TEXTURE_2D, 0);
}

void Texture::setActiveTexture(unsigned int unit) {
    glCall(glActiveTexture, GL_TEXTURE0 + unit);
}