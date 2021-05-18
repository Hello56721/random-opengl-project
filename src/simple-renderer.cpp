#include <glad/glad.h>
#include <opengl-debug.hpp>

#include <simple-renderer.hpp>

void SimpleRenderer::renderMesh(Mesh& mesh, bool useEBO) {
    glCall(glBindVertexArray, mesh.getVAO());
    if (useEBO) {
        int size = 0;
        glCall(glGetBufferParameteriv, GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
        glCall(glDrawElements, GL_TRIANGLES, size / sizeof(unsigned int), GL_UNSIGNED_INT, nullptr);
    } else {
        int size = 0;
        glCall(glGetBufferParameteriv, GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
        glCall(glDrawArrays, GL_TRIANGLES, 0, size / sizeof(Vertex));
    }
    glCall(glBindVertexArray, 0);
}