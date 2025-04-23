#include "..\\FisiereH\\ObiectInteractiv.h"

void ObiectInteractiv::setTextura(sf::Texture& textura)
{
    m_textura = textura;
    m_sprite.setTexture(m_textura, true);
    m_sprite.setTextureRect(sf::IntRect({0, 0}, {(int)m_textura.getSize().x / 2, (int)m_textura.getSize().y}));
}
void ObiectInteractiv::Interactioneaza()
{
    int w = m_textura.getSize().x;
    int h = m_textura.getSize().y;
    m_sprite.setTextureRect(sf::IntRect({w / 2, 0}, {w / 2, h}));
}
