#include "..\\FisiereH\\Obiect.h"

int Obiect::m_cntInventar = 0;

Obiect::Obiect(): m_textura("pictures\\patratAlb.png"), m_sprite(m_textura){}

const sf::Sprite& Obiect::getSprite()
{
    return m_sprite;
}
void Obiect::setTextura(sf::Texture& textura)
{
    m_textura = textura;
    m_sprite.setTexture(m_textura, true);
}
void Obiect::setPosition(sf::Vector2f vector)
{
    m_sprite.setPosition(vector);
}
void Obiect::setScale(sf::Vector2f vector)
{
    m_sprite.setScale(vector);
}
void Obiect::setOrigin(sf::Vector2f vector)
{
    m_sprite.setOrigin(vector);
}
