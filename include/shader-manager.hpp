#ifndef D4C7D082_AE4F_4B1C_AA95_93C630378F89
#define D4C7D082_AE4F_4B1C_AA95_93C630378F89

#include <vector>

class ShaderManager {
private:
    // Default Constructor
    ShaderManager();
    
    // Friend class Shader
    friend class Shader;
    
    // A Vector of all of the shaders
    std::vector<Shader> shaders;
    
public:
    // Obtain the instance
    static void getInstance();
    
    // Destroy Everything (MuaHAHAHAH!!!)
    ~ShaderManager();
}

#endif /* D4C7D082_AE4F_4B1C_AA95_93C630378F89 */
