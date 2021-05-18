#ifndef F16E9586_0432_4949_8C83_9C7E8720A37B
#define F16E9586_0432_4949_8C83_9C7E8720A37B

#include <vertex.hpp>
#include <vector>

class Mesh {
private:
    // The handles to the actual OpenGL objects
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;
    
    // Move owernship over from another Mesh
    void moveFrom(Mesh& src);
    
    // Destroy the Mesh
    void destroy();
    
public:
    // Default Constructor
    Mesh();
    
    // Construct a Mesh from a vector of indices and a vector of vertices
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    
    // Copy Constructor and assignment operator
    Mesh(Mesh& src);
    Mesh& operator=(Mesh rhs);
    
    // Move Constructor and assignment operator
    Mesh(Mesh&& src);
    Mesh& operator=(Mesh&& rhs);
    
    // Swap two Meshes
    static void swap(Mesh& a, Mesh& b);
    
    // Getters for the private fields
    unsigned int getVAO();
    unsigned int getVBO();
    unsigned int getEBO();
    
    // Destructor
    ~Mesh();
};

#endif /* F16E9586_0432_4949_8C83_9C7E8720A37B */
