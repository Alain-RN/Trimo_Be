#include "./libs/texture.hpp"

GameTexture::GameTexture(String path)
{
    this->path = path;

    if (!texture.loadFromFile(path))
    {
        throw std::runtime_error("Erreur lors du chargement de la texture: " + path);
    }
}

Texture& GameTexture::getTexture(void) 
{
    return texture;
}
int GameTexture::getFrame(void) const
{
    return texture.getSize().x / 64;
}