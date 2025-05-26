#ifndef OBIECT_H
#define OBIECT_H

#include <SFML/Graphics.hpp>
#include "ExceptieTextura.h"

class Obiect
{
protected:
    sf::Texture m_textura;
    sf::Sprite m_sprite;
    static int m_cntInventar;
    virtual ~Obiect() = default;
public:
    friend class Joc;

    Obiect();
    virtual Obiect* clone() const = 0;
    const sf::Sprite& getSprite();
    virtual void setTextura(sf::Texture& textura);
    void setPosition(sf::Vector2f vector);
    void setScale(sf::Vector2f vector);
    void setOrigin(sf::Vector2f vector);
    virtual void Interactioneaza() = 0;
};

#endif