#ifndef E3F21D74_B4C9_4BBC_A317_8F4FAFBB33AC
#define E3F21D74_B4C9_4BBC_A317_8F4FAFBB33AC

#include <texture.hpp>
#include <vector>

class TextureManager {
private:
    std::vector<Texture> textures;
    
    // Constructors needs to be private, so we can't create manual instances
    
    TextureManager();
    
    TextureManager(TextureManager& src);
    TextureManager(TextureManager&& src);
    
    // Make the texture class a friend
    friend class Texture;
    
public:
    // Get the instance
    static TextureManager* getInstance();
    
    ~TextureManager();
};

#endif /* E3F21D74_B4C9_4BBC_A317_8F4FAFBB33AC */
