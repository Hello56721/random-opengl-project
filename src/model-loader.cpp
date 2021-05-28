#include <model-loader.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>

Mesh ModelLoader::loadModel(std::string_view path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path.data(), aiProcess_Triangulate | aiProcess_FlipUVs);
    
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "[ERROR]: Can't load model " << path << std::endl;
        return Mesh(
            {
                {{ 0.5f,  0.5f, 0.0f}, {1.0f, 1.0f}},
                {{ 0.5f, -0.5f, 0.0f}, {1.0f, 0.0f}},
                {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}},
                {{-0.5f,  0.5f, 0.0f}, {0.0f, 1.0f}}
            },
            {
                0, 1, 2,
                0, 3, 2
            }
        );
    }
    
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    
    // Process all of the Meshes and lump them together into one Mesh
    for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[i];
        
        // Process the vertices
        for (unsigned int j = 0; j < mesh->mNumVertices; j++) {
            glm::vec3 position;
            position.x = mesh->mVertices[j].x;
            position.y = mesh->mVertices[j].y;
            position.z = mesh->mVertices[j].z;
            
            glm::vec3 textureCoordinate;
            if (mesh->mTextureCoords[0]) {
                textureCoordinate.x = mesh->mTextureCoords[0][j].x;
                textureCoordinate.y = mesh->mTextureCoords[0][j].y;
            } else {
                textureCoordinate = glm::vec3(1.0f, 1.0f, 1.0f);
            }
            
            Vertex vertex;
            vertex.position = position;
            vertex.textureCoordinate = textureCoordinate;
            vertices.push_back(vertex);
        }
        
        // Process the indices
        for (unsigned int j = 0; j < mesh->mNumFaces; j++) {
            aiFace face = mesh->mFaces[j];
            
            for (unsigned int k = 0; k < face.mNumIndices; k++) {
                indices.push_back(face.mIndices[k]);
            }
        }
    }
    
    return Mesh(vertices, indices);
}