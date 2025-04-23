#ifndef ANIMAL_H
#define ANIMAL_H

#include <SFML/Graphics.hpp>

class Animal
{
protected:
    sf::Texture m_textura;
    sf::Sprite m_sprite;
    sf::Clock m_ceas;
    bool m_orientare;
    bool m_frameIdle;
    float m_timpAnimatieIdle;
public:
    Animal();
    virtual void setTextura(sf::Texture& textura);
    void animatieIdle();
    void Initializare();
    void setPosition(sf::Vector2f vector);
    void setOrientare(bool orientare);
    const sf::Sprite& getSprite();
};

#endif
