#ifndef D4C7D082_AE4F_4B1C_AA95_93C630378F89
#define D4C7D082_AE4F_4B1C_AA95_93C630378F89

#include <vector>
#include <shader-class.hpp>

class ShaderManager {
private:
    // Default Constructor is made private so instances can't be created
    ShaderManager();
    
    // Made the copy constructor and assignment operator private so copies can't be made
    ShaderManager(ShaderManager& src);
    ShaderManager& operator=(ShaderManager& rhs);
    
    // Friend class Shader
    friend class Shader;
    
    // A Vector of all of the shaders
    std::vector<Shader> shaders;
    
public:
    // Obtain the instance
    static ShaderManager& getInstance();
    
    // Destroy Everything (MuaHAHAHAH!!!)
    ~ShaderManager();
};

#endif /* D4C7D082_AE4F_4B1C_AA95_93C630378F89 */
