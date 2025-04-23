#include "..\\FisiereH\\Joc.h"

Inamic::Inamic()
{
    m_timpAnimatieIdle = 0.5f;
    m_timpAnimatieMers = 0.25f;
    m_onGround = 1;
    m_velocity = 0.f;
    m_pasnic = 0;
}

void Inamic::animatieMers()
{
    m_sprite.setTextureRect(sf::IntRect({512 * m_frameMers, 512}, {512, 512}));
    if(m_ceas.getElapsedTime().asSeconds() >= m_timpAnimatieMers)
    {
        m_frameMers = (m_frameMers + 1) % 3;
        m_ceas.restart();
    }
}
void Inamic::setViteza(float viteza)
{
    m_viteza = viteza;
}
void Inamic::setPlatforma(sf::FloatRect platforma)
{
    m_platformaCurenta = platforma;
}
bool Inamic::intersectieX(sf::FloatRect platforma)
{
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    float xl = spriteBounds.position.x - spriteBounds.size.x + 20.f;
    float xr = spriteBounds.position.x + spriteBounds.size.x - 24.f;

    float pxl = platforma.position.x;
    float pxr = pxl + platforma.size.x;

    float xlmax = std::max(xl, pxl);
    float xrmin = std::min(xr, pxr);

    if(xlmax < xrmin)
        return 1;
    return 0;
}
bool Inamic::intersectieY(sf::FloatRect platforma)
{
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    float yt = spriteBounds.position.y - spriteBounds.size.y - 40.f;
    float yb = spriteBounds.position.y + spriteBounds.size.y;
    
    float pyt = platforma.position.y;
    float pyb = pyt + platforma.size.y;
    
    float ytmax = std::max(yt, pyt);
    float ybmin = std::min(yb, pyb);

    if(ytmax < ybmin)
        return 1;
    return 0;
}
void Inamic::onGround()
{
    if(m_onGround == 1)
    {
        if(!this->intersectieX(m_platformaCurenta))
        {
            m_onGround = 0;
        }
    }
}
bool Inamic::esteLanga(Obiect* obiect)
{
    sf::FloatRect obBounds = obiect->getSprite().getGlobalBounds();
    bool intX = (std::abs(obBounds.position.x - m_sprite.getGlobalBounds().position.x) < 60.f);
    return intX && this->intersectieY(obBounds);
}
void Inamic::mergiLa(Obiect* obiect)
{
    this->onGround();

    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    if(m_onGround)
    {
        sf::FloatRect obBounds = obiect->getSprite().getGlobalBounds();
        if(m_platformaCurenta == Joc::m_platforme[5]
           || (std::abs(spriteBounds.position.y - obBounds.position.y) < m_viteza 
               && spriteBounds.position.x > obBounds.position.x))
        {
            if(spriteBounds.position.x / 2.f > 54.f)
                m_sprite.move({-m_viteza, 0});
            if(m_orientare == 0)
            {
                m_sprite.scale({-1.0f, 1.0f});
                m_orientare = 1;
            }
        }
        else
        {
            if(spriteBounds.position.x + spriteBounds.size.x < 1480.f)
                m_sprite.move({m_viteza, 0});
            if(m_orientare == 1)
            {
                m_sprite.scale({-1.0f, 1.0f});
                m_orientare = 0;
            }
        }
    }
    else
    {
        m_velocity += 0.5f;
        m_sprite.move({0, m_velocity});

        for(const sf::FloatRect& platforma: Joc::m_platforme)
            if(this->intersectieX(platforma) && this->intersectieY(platforma)
               && m_velocity > 0 
               && spriteBounds.position.y + spriteBounds.size.y / 2.f - m_velocity < platforma.position.y)
            {
                m_sprite.setPosition({spriteBounds.position.x + spriteBounds.size.x / 2.f, platforma.position.y - spriteBounds.size.y / 2.f});
                m_velocity = 0;
                m_onGround = 1;
                m_platformaCurenta = platforma;
                break;
            }
    }
    this->animatieMers();
}

bool Inamic::getPasnic()
{
    return m_pasnic;
}
void Inamic::setPasnic(bool pasnic)
{
    m_pasnic = pasnic;
}
