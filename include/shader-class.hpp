#ifndef D563D817_6A65_4428_9FAE_F01285C37BA5
#define D563D817_6A65_4428_9FAE_F01285C37BA5

#include <string_view>

class Shader {
private:
    unsigned int program;
    
public:
    // Default Constructor
    Shader();
    
    // Constructor
    Shader(std::string_view path);
    
    // Use/Activate the shader
    void use() const;
    
    // Set uniforms
    void setUniform(std::string_view name, float value) const;
};

#endif /* D563D817_6A65_4428_9FAE_F01285C37BA5 */
