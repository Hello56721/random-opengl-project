#ifndef C0226920_2CC9_46E4_90BC_5D31653C0222
#define C0226920_2CC9_46E4_90BC_5D31653C0222

#include <string_view>

namespace ShaderUtils {
    // Create a shader object and return it's handle
    unsigned int createShader(const char* source, unsigned int type, std::string_view name);
    
    // Create a shader program and return it's handle
    unsigned int createProgram(unsigned int vertex, unsigned int fragment, std::string_view name);
}

#endif /* C0226920_2CC9_46E4_90BC_5D31653C0222 */
