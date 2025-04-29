#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Player {

private:
    Sprite sprite;
    Texture walkTexture;
    Texture pauseTexture;
    float speed;
public:
    Player(Texture walkTexture, Texture pauseTexture, float speed);
    
    void pause();

    void walkRight(int iFrame);

    void walkLeft(int iFrame);

    Sprite& getSprite();

};

#endif
