#ifndef B00FA4FB_806D_46BD_BA09_2BDBDB3FE641
#define B00FA4FB_806D_46BD_BA09_2BDBDB3FE641

namespace std {
    template<typename T>
    class basic_string_view;

    typedef basic_string_view<char> string_view;
}

class Texture {
private:
    unsigned int texture;
    
public:
    // Default Constructor
    Texture();
    
    // Construct a texture from a path
    Texture(std::string_view path);
    
    // Bind the texture
    void bind();
    
    // Unbind the texture
    void unbind();
    
    // Set the active texture unit
    static void setActiveTexture(unsigned int unit);
};

#endif /* B00FA4FB_806D_46BD_BA09_2BDBDB3FE641 */
