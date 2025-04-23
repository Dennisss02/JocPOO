#include "..\\FisiereH\\Fundal.h"

Fundal::Fundal(): m_texturaFundal("pictures\\patratAlb.png"), m_spriteFundal(m_texturaFundal), m_texturaLumina("pictures\\patratAlb.png"), m_spriteLumina(m_texturaLumina){}

void Fundal::setSpriteFundal(sf::Texture& textura)
{
    m_texturaFundal = textura;
    m_spriteFundal.setTexture(m_texturaFundal, true);
}
void Fundal::setSpriteLumina(sf::Texture& textura)
{
    m_texturaLumina = textura;
    m_spriteLumina.setTexture(m_texturaLumina, true);
    m_spriteLumina.setTextureRect(sf::IntRect({0, 0}, {(int)m_texturaFundal.getSize().x, (int)m_texturaFundal.getSize().y}));
}
const sf::Sprite& Fundal::getSpriteFundal()
{
    return m_spriteFundal;
}
const sf::Sprite& Fundal::getSpriteLumina()
{
    return m_spriteLumina;
}
void Fundal::setScale(sf::Vector2f vector)
{
    m_spriteFundal.setScale(vector);
    m_spriteLumina.setScale(vector);
}
void Fundal::setPosition(sf::Vector2f vector)
{
    m_spriteFundal.setPosition(vector);
    m_spriteLumina.setPosition(vector);
}
float Fundal::getX()
{
    return m_texturaFundal.getSize().x;
}
float Fundal::getY()
{
    return m_texturaFundal.getSize().y;
}

void Fundal::schimbaLumina()
{
    m_spriteLumina.setTextureRect(sf::IntRect({(int)m_texturaFundal.getSize().x, 0}, {(int)m_texturaFundal.getSize().x, (int)m_texturaFundal.getSize().y}));
}
