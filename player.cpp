#include "./libs/player.hpp"

Player::Player(Texture walkTexture, Texture pauseTexture, float speed)
{
    this->walkTexture = walkTexture;
    this->pauseTexture = pauseTexture;
    this->speed = speed;

    sprite.setTextureRect(IntRect(64 * 0, 28, 64, 68));
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(300, 300);
}

void Player::walkRight(int iFrame)
{
    sprite.setTexture(walkTexture);
    sprite.setScale(1.f, 1.f);
    sprite.setTextureRect(IntRect(64 * (iFrame % 12), 28, 64, 68));
}

void Player::walkLeft(int iFrame)
{
    sprite.setTexture(walkTexture);
    sprite.setScale(-1.f, 1.f);
    sprite.setTextureRect(IntRect(64 * (iFrame % 12), 28, 64, 68));
}

void Player::pause()
{
    sprite.setTexture(pauseTexture);
    sprite.setTextureRect(IntRect(0, 28, 64, 68)); // Première frame de pause
}

Sprite& Player::getSprite()
{
    return sprite;
}
