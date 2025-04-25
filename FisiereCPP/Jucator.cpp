#include "..\\FisiereH\\Joc.h"

Jucator::Jucator()
{
    m_timpAnimatieIdle = 0.5f;
    m_timpAnimatieMers = 0.25f;
    m_onGround = 1;
    m_velocity = 0.f;
}

void Jucator::animatieMers()
{
    m_sprite.setTextureRect(sf::IntRect({512 * m_frameMers, 512}, {512, 512}));
    if(m_ceas.getElapsedTime().asSeconds() >= m_timpAnimatieMers)
    {
        m_frameMers = (m_frameMers + 1) % 3;
        m_ceas.restart();
    }
}

void Jucator::animatiePerete()
{
    m_sprite.setTextureRect(sf::IntRect({512 * m_frameIdle, 1024}, {512, 512}));
    if(m_ceas.getElapsedTime().asSeconds() >= 1.f)
    {
        m_frameIdle = !m_frameIdle;
        m_ceas.restart();
    }
}

void Jucator::animatieSalt()
{
    m_sprite.setTextureRect(sf::IntRect({512 * (m_velocity > 0), 1536}, {512, 512}));
}

bool Jucator::intersectieX(sf::FloatRect platforma)
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
bool Jucator::intersectieY(sf::FloatRect platforma)
{
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    float yt = spriteBounds.position.y - spriteBounds.size.y;
    float yb = spriteBounds.position.y + spriteBounds.size.y;
    
    float pyt = platforma.position.y;
    float pyb = pyt + platforma.size.y;
    
    float ytmax = std::max(yt, pyt);
    float ybmin = std::min(yb, pyb);

    if(ytmax < ybmin)
        return 1;
    return 0;
}

void Jucator::onGround()
{
    if(m_onGround == 1)
    {
        if(!this->intersectieX(m_platformaCurenta))
        {
            m_onGround = 0;
        }
    }
}

void Jucator::coliziuneTop(sf::FloatRect platforma)
{
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    if(m_onGround == 0 && m_velocity < 0
        && this->intersectieX(platforma) && this->intersectieY(platforma)
        && spriteBounds.position.y - spriteBounds.size.y / 2.f + m_velocity > platforma.position.y + platforma.size.y)
    {
        m_velocity = 0.f;
    }
}

void Jucator::Salt()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
       && m_onGround == 1)
    {
        m_onGround = 0;
        m_velocity = -13.f;
    }
    if(m_onGround == 0)
    {
        m_velocity += 0.5f;
        m_sprite.move({0, m_velocity});

        sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();

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

        if(m_onGround == 0)
            this->animatieSalt();
    }
    this->onGround();
    if(Joc::m_pasi[1] == 0)
        this->coliziuneTop(Joc::m_platforme[6]);
}

void Jucator::Control()
{
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    int miscare = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if(spriteBounds.position.x / 2.f > 54.f)
        {
            m_sprite.move({-m_viteza, 0});
            miscare = 1;
        }
        else
            miscare = 2;
        
        if(m_orientare == 0)
        {
            m_sprite.scale({-1.0f, 1.0f});
            m_orientare = 1;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if(spriteBounds.position.x + spriteBounds.size.x < 1480.f)
        {
            m_sprite.move({m_viteza, 0});
            miscare = 1;
        }
        else
            miscare = 2;
        
        if(m_orientare == 1)
        {
            m_sprite.scale({-1.0f, 1.0f});
            m_orientare = 0;
        }
    }

    if(miscare == 0)
        this->animatieIdle();
    else
    {
        if(miscare == 1)
            this->animatieMers();
        else
            this->animatiePerete();
    }
    
    this->Salt();
}

bool Jucator::esteLanga(Obiect* obiect)
{
    sf::FloatRect obBounds = obiect->getSprite().getGlobalBounds();
    return this->intersectieX(obBounds) && this->intersectieY(obBounds);
}

bool Jucator::esteLanga(Animal* animal)
{
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    sf::FloatRect animalBounds = animal->getSprite().getGlobalBounds();

    float xl = spriteBounds.position.x - spriteBounds.size.x / 2.f;
    float xr = spriteBounds.position.x + spriteBounds.size.x / 2.f;

    float axl = animalBounds.position.x - animalBounds.size.x / 2.f;
    float axr = animalBounds.position.x + animalBounds.size.x / 2.f;

    float xlmax = std::max(xl, axl);
    float xrmin = std::min(xr, axr);

    float yt = spriteBounds.position.y - spriteBounds.size.y / 2.f;
    float yb = spriteBounds.position.y + spriteBounds.size.y / 2.f;
    
    float ayt = animalBounds.position.y - animalBounds.size.y / 2.f - 30.f;
    float ayb = animalBounds.position.y + animalBounds.size.y / 2.f;
    
    float ytmax = std::max(yt, ayt);
    float ybmin = std::min(yb, ayb);

    if(xlmax < xrmin && ytmax < ybmin)
        return 1;
    return 0;    
}

void Jucator::interactiuneObiecte()
{
    int n = (int)Joc::m_obiecte.size();
    for(int i = 0; i < n; i++)
    {
        Obiect* p_ob = Joc::m_obiecte[i];
        if(this->esteLanga(p_ob))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
            {
                switch(i)
                {
                    case 0:
                        if(Joc::m_pasi[0] == 0)
                        {
                            p_ob->Interactioneaza();
                            ObiectConsumabil* ob = dynamic_cast<ObiectConsumabil*>(Joc::m_obiecte[4]);
                            ob->Afiseaza();
                            Joc::m_pasi[0] = 1;
                        }
                        break;
                    case 1:
                        if(Joc::m_pasi[0] == 1 && Joc::m_pasi[1] == 0)
                        {
                            p_ob->Interactioneaza();
                            ObiectConsumabil* ob = dynamic_cast<ObiectConsumabil*>(Joc::m_obiecte[4]);
                            ob->Interactioneaza();
                            Joc::m_pasi[1] = 1;
                            Joc::m_platforme.pop_back();
                        }
                        break;
                    case 2:
                        if(Joc::m_pasi[1] == 1 && Joc::m_pasi[2] == 0)
                        {
                            p_ob->Interactioneaza();
                            ObiectConsumabil* ob = dynamic_cast<ObiectConsumabil*>(Joc::m_obiecte[5]);
                            ob->Afiseaza();
                            Joc::m_pasi[2] = 1;
                        }
                        break;
                    case 3:
                        if(Joc::m_pasi[2] == 1 && Joc::m_pasi[3] == 0)
                        {
                            p_ob->Interactioneaza();
                            ObiectConsumabil* ob = dynamic_cast<ObiectConsumabil*>(Joc::m_obiecte[5]);
                            ob->Interactioneaza();
                            ObiectConsumabil* obNou = dynamic_cast<ObiectConsumabil*>(Joc::m_obiecte[6]);
                            obNou->Afiseaza();
                            Joc::m_pasi[3] = 1;
                            break;
                        }
                }
                
                break;
            }
        }
    }
    if(Joc::m_pasi[3] == 1 && Joc::m_pasi[4] == 0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
        {
            ObiectConsumabil* ob = dynamic_cast<ObiectConsumabil*>(Joc::m_obiecte[6]);
            
            sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
            float obX, obY;
            obX = spriteBounds.position.x + spriteBounds.size.x / 2.f;
            obY = m_platformaCurenta.position.y - spriteBounds.size.y / 2.f + 16.f;

            ob->setPosition({obX, obY});
            Joc::m_pasi[4] = 1;
        }
    }
}

void Jucator::setViteza(float viteza)
{
    m_viteza = viteza;
}
void Jucator::setVelocity(float velocity)
{
    m_velocity = velocity;
}
void Jucator::setPlatforma(sf::FloatRect platforma)
{
    m_platformaCurenta = platforma;
}
sf::FloatRect Jucator::getPlatformaCurenta()
{
    return m_platformaCurenta;
}