#ifndef AJUTOR_H
#define AJUTOR_H

#include "Animal.h"

class Ajutor: public Animal
{
private:
    sf::Texture m_texturaHint;
    sf::Sprite m_spriteHint;
    sf::Font m_fontHint;
    sf::Text m_textHint;
public:
    Ajutor();
    void setTexturaHint(sf::Texture& textura);
    void initHint();
    const sf::Sprite& getSpriteHint();
    void setBubbleScale(sf::Vector2f scale);
    const sf::Text& afiseazaHint();
};

#endif