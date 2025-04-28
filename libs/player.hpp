#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Player {

private:
    Sprite sprite;
    Texture walkTexture;
    Texture PauseTexture;
    float speed;

public:
    Player(Texture walkTexture, Texture PauseTexture, float speed);

    void walkRight();

    void walkLeft();

    Sprite& getSprite();
};

#endif
