#include "./libs/player.hpp"

Player::Player(Texture walkTexture, Texture PauseTexture, float speed)
{
    this->walkTexture = walkTexture;
    this->PauseTexture = PauseTexture;
    this->speed = speed;
}

void Player::walkRight()
{
    sprite.setTexture(walkTexture);
}

void Player::walkLeft()
{
    sprite.setTexture(walkTexture);
    sprite.setScale(-1.f, 1.f);
}

Sprite& Player::getSprite()
{
    return sprite;
}
