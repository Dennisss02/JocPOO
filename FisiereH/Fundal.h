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
    sf::Texture m_texturaVictorie;
    sf::Sprite m_spriteVictorie;
public:
    Fundal();
    void setSpriteFundal(sf::Texture& textura);
    void setSpriteLumina(sf::Texture& textura);
    void setSpriteVictorie(sf::Texture& textura);
    const sf::Sprite& getSpriteFundal();
    const sf::Sprite& getSpriteLumina();
    const sf::Sprite& getSpriteVictorie();
    void setScale(sf::Vector2f vector);
    float getX();
    float getY();
    void schimbaLumina();
};

#endif