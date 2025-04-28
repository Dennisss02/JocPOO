#include "..\\FisiereH\\Animal.h"

Animal::Animal() : m_textura(sf::Vector2u(200, 200)), m_sprite(m_textura)
{
    m_orientare = 0;
    m_frameIdle = 0;
    m_timpAnimatieIdle = 1.f;
}

void Animal::setTextura(sf::Texture& textura)
{
    m_textura = textura;
}
void Animal::setOrientare(bool orientare)
{
    m_orientare = orientare;
}

void Animal::animatieIdle()
{
    m_sprite.setTextureRect(sf::IntRect({512 * m_frameIdle, 0}, {512, 512}));
    if(m_ceas.getElapsedTime().asSeconds() >= m_timpAnimatieIdle)
    {
        m_frameIdle = !m_frameIdle;
        m_ceas.restart();
    }
}

void Animal::Initializare()
{
    m_sprite.setOrigin({256.f, 256.f});
    m_sprite.setScale({0.2f, 0.2f});
}

void Animal::setPosition(sf::Vector2f vector)
{
    m_sprite.setPosition(vector);
}

const sf::Sprite& Animal::getSprite()
{
    return m_sprite;
}
