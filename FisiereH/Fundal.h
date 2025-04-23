#ifndef FUNDAL_H
#define FUNDAL_H

#include <SFML/Graphics.hpp>

class Fundal
{
private:
    sf::Texture m_texturaFundal;
    sf::Sprite m_spriteFundal;
    sf::Texture m_texturaLumina;
    sf::Sprite m_spriteLumina;
public:
    Fundal();
    void setSpriteFundal(sf::Texture& textura);
    void setSpriteLumina(sf::Texture& textura);
    const sf::Sprite& getSpriteFundal();
    const sf::Sprite& getSpriteLumina();
    void setScale(sf::Vector2f vector);
    void setPosition(sf::Vector2f vector);
    float getX();
    float getY();
    void schimbaLumina();
};

#endif