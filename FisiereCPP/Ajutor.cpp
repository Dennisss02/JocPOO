#include "..\\FisiereH\\Joc.h"

Ajutor::Ajutor(): m_texturaHint("pictures\\Bubble.png"), m_spriteHint(m_texturaHint), m_fontHint("Silkscreen\\slkscr.ttf"), m_textHint(m_fontHint)
{
    m_timpAnimatieIdle = 1.f;
}

void Ajutor::initHint()
{
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    float xB, yB;
    xB = spriteBounds.position.x - spriteBounds.size.x / 2.f - 188.f;
    yB = spriteBounds.position.y - spriteBounds.size.y / 2.f - 40.f;
    m_spriteHint.setPosition({xB, yB});

    m_textHint.setCharacterSize(16.f);
    m_textHint.setFillColor(sf::Color::Black);
    m_textHint.setPosition({xB + 8.f, yB + 8.f});
}

const sf::Sprite& Ajutor::getSpriteHint()
{
    return m_spriteHint;
}

void Ajutor::setBubbleScale(sf::Vector2f scale)
{
    m_spriteHint.setScale(scale);
}

const sf::Text& Ajutor::afiseazaHint()
{
    if(Joc::m_pasi[0] == 0)
    {
        m_textHint.setString("Imi plac cutiile, \nsunt atat de \ncomode!");
    }
    else
        if(Joc::m_pasi[1] == 0)
        {
            m_textHint.setString("La ce altceva \npoate fi buna \no cheie... \nghici!");
        }
        else
            if(Joc::m_pasi[2] == 0)
            {
                m_textHint.setString("Nu m-as fi gandit \nca o ranga se \nfoloseste la \ngradinarit, dar \nce stiu eu...");
            }
            else
                if(Joc::m_pasi[3] == 0)
                {
                    m_textHint.setString("Subsolul e \nplin de praf, \nnu imi place \nsa dorm acolo, \nmai ales pe \ncufar.");
                }
                else
                    if(Joc::m_pasi[4] == 0)
                    {
                        m_textHint.setString("Sunt foarte \nenervanti cainii, \nnoroc ca sunt \nusor de distras!");
                    }
                    else
                    {
                        m_textHint.setString("Imi e asa foame, \nnu am mai mancat \nde 5 minute...");
                    }
    return m_textHint;
}
