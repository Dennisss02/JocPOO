#include "..\\FisiereH\\ObiectInteractiv.h"

Obiect* ObiectInteractiv::clone() const
{
    return new ObiectInteractiv(*this);
}

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

ObiectInteractiv* ObiectInteractiv::creeazaCutie(sf::Vector2f pozitie)
{
    ObiectInteractiv* cutie = new ObiectInteractiv();
    
    try
    {
        sf::Texture texturaObiect;
        if(!texturaObiect.loadFromFile("pictures\\Cutii.png"))
            throw ExceptieTextura("pictures\\Cutii.png");
        
        cutie->setTextura(texturaObiect);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    cutie->setPosition(pozitie);
    sf::FloatRect obBounds = cutie->getSprite().getGlobalBounds();
    cutie->setOrigin({128.f, 128.f});
    return cutie;
}
ObiectInteractiv* ObiectInteractiv::creeazaTrapa(sf::Vector2f pozitie)
{
    ObiectInteractiv* trapa = new ObiectInteractiv();
    
    try
    {
        sf::Texture texturaObiect;
        if(!texturaObiect.loadFromFile("pictures\\Trapa.png"))
            throw ExceptieTextura("pictures\\Trapa.png");
        
        trapa->setTextura(texturaObiect);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    trapa->setPosition(pozitie);
    sf::FloatRect obBounds = trapa->getSprite().getGlobalBounds();
    trapa->setOrigin({128.f, 128.f});
    return trapa;
}
ObiectInteractiv* ObiectInteractiv::creeazaVaza(sf::Vector2f pozitie)
{
    ObiectInteractiv* vaza = new ObiectInteractiv();
    
    try
    {
        sf::Texture texturaObiect;
        if(!texturaObiect.loadFromFile("pictures\\Vaza.png"))
            throw ExceptieTextura("pictures\\Vaza.png");
        
        vaza->setTextura(texturaObiect);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    vaza->setPosition(pozitie);
    sf::FloatRect obBounds = vaza->getSprite().getGlobalBounds();
    vaza->setOrigin({128.f, 128.f});
    return vaza;
}
ObiectInteractiv* ObiectInteractiv::creeazaCufar(sf::Vector2f pozitie)
{
    ObiectInteractiv* cufar = new ObiectInteractiv();
    
    try
    {
        sf::Texture texturaObiect;
        if(!texturaObiect.loadFromFile("pictures\\Cufar.png"))
            throw ExceptieTextura("pictures\\Cufar.png");
        
        cufar->setTextura(texturaObiect);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    cufar->setPosition(pozitie);
    sf::FloatRect obBounds = cufar->getSprite().getGlobalBounds();
    cufar->setOrigin({128.f, 128.f});
    return cufar;
}
