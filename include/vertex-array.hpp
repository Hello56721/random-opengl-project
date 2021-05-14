#ifndef CC4C3EA4_4EE5_470F_A9C1_DB79CC5C9F6C
#define CC4C3EA4_4EE5_470F_A9C1_DB79CC5C9F6C

class VertexArray {
private:
    unsigned int vertexArray;
    
public:
    // Constructor
    VertexArray();
    
    // Copy constructor
    VertexArray(VertexArray& src);
    
    // copy assignment operator
    VertexArray& operator=(VertexArray rhs);
};

#endif /* CC4C3EA4_4EE5_470F_A9C1_DB79CC5C9F6C */
