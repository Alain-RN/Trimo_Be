#ifndef TEXTURE
#define TEXTURE

#include<SFML/Graphics.hpp>

using namespace sf;

class GameTexture
{
private:
    Texture texture;
    String path;
public:
    GameTexture(String path);
    Texture& getTexture(void);
    int getFrame(void)const;
};



#endif