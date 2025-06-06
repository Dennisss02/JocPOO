#include "..\\FisiereH\\Joc.h"

Joc* Joc::Instanta = NULL;

std::vector<sf::FloatRect> Joc::m_platforme;
std::vector<Obiect*> Joc::m_obiecte;
std::vector<bool> Joc::m_pasi(5, 0);

Joc::Joc()
{
    m_window = new sf::RenderWindow(sf::VideoMode({(unsigned int)1496, (unsigned int)850}), "Goana dupa pliculete!");
    m_fundal = new Fundal();

    /*
    m_jucator = new Entitate<Jucator>();
    m_inamic = new Entitate<Inamic>();
    m_ajutor = new Entitate<Ajutor>();
    */

    m_ceasHint = new sf::Clock();
    m_ceasHint->reset();
}

Joc* Joc::getInstanta()
{
    if(Joc::Instanta == NULL)
        Instanta = new Joc();
    return Joc::Instanta;
}

void Joc::initWindow()
{
    m_window->setFramerateLimit(60);
    m_window->setVerticalSyncEnabled(false);
}
void Joc::initFundal()
{
    try
    {
        sf::Texture texturaFundal;
        if(!texturaFundal.loadFromFile("pictures\\Fundal.png"))
            throw ExceptieTextura("pictures\\Fundal.png");
        
        m_fundal->setSpriteFundal(texturaFundal);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    try
    {
        sf::Texture texturaLumina;
        if(!texturaLumina.loadFromFile("pictures\\Lumina.png"))
            throw ExceptieTextura("pictures\\Lumina.png");
        
        m_fundal->setSpriteLumina(texturaLumina);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    try
    {
        sf::Texture texturaVictorie;
        if(!texturaVictorie.loadFromFile("pictures\\Comoara.png"))
            throw ExceptieTextura("pictures\\Comoara.png");
        
        m_fundal->setSpriteVictorie(texturaVictorie);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }
    
    m_fundal->setScale({(float)m_window->getSize().x / m_fundal->getX(), 
                        (float)m_window->getSize().y / m_fundal->getY()});
}
void Joc::initPlatforme()
{
    m_platforme.push_back(sf::FloatRect({54.f, 830.f}, {1400.f, 8.f}));     /// 0 podea subsol
    m_platforme.push_back(sf::FloatRect({54.f, 534.f}, {1080.f, 8.f}));     /// 1 podea parter
    m_platforme.push_back(sf::FloatRect({1396.f, 534.f}, {60.f, 8.f}));     /// 2
    m_platforme.push_back(sf::FloatRect({1268.f, 670.f}, {8.f, 8.f}));      /// 3 etajera subsol
    m_platforme.push_back(sf::FloatRect({80.f, 400.f}, {32.f, 8.f}));       /// 4 scara parter
    m_platforme.push_back(sf::FloatRect({228.f, 266.f}, {1360.f, 8.f}));    /// 5 podea etaj
    
    m_platforme.push_back(sf::FloatRect({1160.f, 464.f}, {244.f, 8.f}));    /// 6 trapa
}
void Joc::initJucator()
{
    try
    {
        sf::Texture texturaJucator;
        if(!texturaJucator.loadFromFile("pictures\\Miti.png"))
            throw ExceptieTextura("pictures\\Miti.png");
        
        m_jucator->setTextura(texturaJucator);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    m_jucator->Initializare();
    m_jucator->setPosition({250.f, 780.f});
    m_jucator->setOrientare(0);
    m_jucator->setViteza(4.f);
    m_jucator->setVelocity(0.f);
    m_jucator->setPlatforma(m_platforme[0]);
    m_jucator->onGround();
}
void Joc::initInamic()
{
    try
    {
        sf::Texture texturaInamic;
        if(!texturaInamic.loadFromFile("pictures\\Badi.png"))
            throw ExceptieTextura("pictures\\Badi.png");
        
        m_inamic->setTextura(texturaInamic);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    m_inamic->Initializare();
    m_inamic->setPosition({1100.f, 210.f});
    m_inamic->setOrientare(0);
    m_inamic->setViteza(4.f);
    m_inamic->setPlatforma(m_platforme[5]);
    m_inamic->onGround();
}
void Joc::initAjutor()
{
    try
    {
        sf::Texture texturaAjutor;
        if(!texturaAjutor.loadFromFile("pictures\\Flafi.png"))
            throw ExceptieTextura("pictures\\Flafi.png");
        
        m_ajutor->setTextura(texturaAjutor);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }
    
    m_ajutor->Initializare();
    m_ajutor->setPosition({1092.f, 475.f});

    try
    {
        sf::Texture texturaHint;
        if(!texturaHint.loadFromFile("pictures\\Bubble.png"))
            throw ExceptieTextura("pictures\\Bubble.png");
        
        m_ajutor->setTexturaHint(texturaHint);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    m_ajutor->initHint();
    m_ajutor->setBubbleScale({(float)m_window->getSize().x / m_fundal->getX(), 
                              (float)m_window->getSize().y / m_fundal->getY()});
}
/*
void Joc::adaugaObiectInteractiv(std::string caleImagine)
{
    sf::Vector2f scale = {(float)m_window->getSize().x / m_fundal->getX(), 
                          (float)m_window->getSize().y / m_fundal->getY()};
    
    m_obiecte.push_back(new ObiectInteractiv());
    int n = m_obiecte.size() - 1;

    try
    {
        sf::Texture texturaObiect;
        if(!texturaObiect.loadFromFile(caleImagine))
            throw ExceptieTextura(caleImagine);
        
        m_obiecte[n]->setTextura(texturaObiect);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    m_obiecte[n]->setScale(scale);
}
*/
void Joc::adaugaObiectConsumabil(std::string caleImagine)
{
    sf::Vector2f scale = {(float)m_window->getSize().x / m_fundal->getX(), 
                          (float)m_window->getSize().y / m_fundal->getY()};
    
    m_obiecte.push_back(new ObiectConsumabil());
    int n = m_obiecte.size() - 1;
    
    try
    {
        sf::Texture texturaObiect;
        if(!texturaObiect.loadFromFile(caleImagine))
            throw ExceptieTextura(caleImagine);
        
        m_obiecte[n]->setTextura(texturaObiect);
    }
    catch(const ExceptieTextura& e)
    {
        e.afiseazaEroare();
    }

    m_obiecte[n]->setScale(scale);
    sf::FloatRect obBounds = m_obiecte[n]->getSprite().getGlobalBounds();
    m_obiecte[n]->setOrigin({128.f, 128.f});
    Obiect::m_cntInventar++;
}
void Joc::initObiecte()
{
    /*
    this->adaugaObiectInteractiv("pictures\\Cutii.png");
    m_obiecte[0]->setPosition({502.f, 664.f});
    this->adaugaObiectInteractiv("pictures\\Trapa.png");
    m_obiecte[1]->setPosition({1254.f, 416.f});
    this->adaugaObiectInteractiv("pictures\\Vaza.png");
    m_obiecte[2]->setPosition({504.f, 390.f});
    this->adaugaObiectInteractiv("pictures\\Cufar.png");
    m_obiecte[3]->setPosition({789.f, 729.f});
    */

    sf::Vector2f scale = {(float)m_window->getSize().x / m_fundal->getX(), 
                          (float)m_window->getSize().y / m_fundal->getY()};
    
    m_obiecte.push_back(ObiectInteractiv::creeazaCutie({549.f, 712.f}));
    m_obiecte[0]->setScale(scale);
    m_obiecte.push_back(ObiectInteractiv::creeazaTrapa({1301.f, 464.f}));
    m_obiecte[1]->setScale(scale);
    m_obiecte.push_back(ObiectInteractiv::creeazaVaza({551.f, 438.f}));
    m_obiecte[2]->setScale(scale);
    m_obiecte.push_back(ObiectInteractiv::creeazaCufar({835.5f, 777.f}));
    m_obiecte[3]->setScale(scale);

    this->adaugaObiectConsumabil("pictures\\Cheie.png");
    this->adaugaObiectConsumabil("pictures\\Ranga.png");
    this->adaugaObiectConsumabil("pictures\\Carne.png");
}

void Joc::Initializare()
{
    this->initWindow();
    this->initFundal();
    this->initPlatforme();
    this->initJucator();
    this->initInamic();
    this->initAjutor();
    this->initObiecte();
}

void Joc::drawFundal()
{
    m_window->draw(m_fundal->getSpriteFundal());
}

template<class T>
void drawEntitate(sf::RenderWindow* window, T ob)
{
    window->draw(ob->getSprite());
}

/*
void Joc::drawJucator()
{
    m_window->draw(m_jucator->getSprite());
}
void Joc::drawInamic()
{
    m_window->draw(m_inamic->getSprite());
}
void Joc::drawAjutor()
{
    m_window->draw(m_ajutor->getSprite());
}
*/

void Joc::drawObiecte()
{
    for(Obiect* obiect: m_obiecte)
    {
        if(auto* ob = dynamic_cast<ObiectConsumabil*>(obiect))
            if(ob->getVizibil() == 0)
                continue;
        drawEntitate(m_window, obiect);
    }
}
void Joc::drawLumina()
{
    m_window->draw(m_fundal->getSpriteLumina());
}

void Joc::afiseazaHint()
{
    m_window->draw(m_ajutor->getSpriteHint());
    m_window->draw(m_ajutor->afiseazaHint());
    if(m_ceasHint->getElapsedTime().asSeconds() >= 4.f)
    {
        m_ceasHint->reset();
        m_afHint = 0;
    }
}

void Joc::resetStatic()
{
    m_platforme.clear();
    m_obiecte.clear();
    m_pasi.clear();
    m_pasi.resize(5, 0);
    Obiect::m_cntInventar = 0;
}
void Joc::Restart()
{
    sf::Font fontRestart("Silkscreen\\slkscrb.ttf");
    sf::Text textRestart(fontRestart);
    textRestart.setString("Ai pierdut...");
    textRestart.setCharacterSize(60);
    textRestart.setFillColor(sf::Color::Black);
    textRestart.setOutlineColor(sf::Color::White);
    textRestart.setOutlineThickness(4.f);
    textRestart.setOrigin({textRestart.getGlobalBounds().size.x / 2.f, textRestart.getGlobalBounds().size.y / 2.f});
    textRestart.setPosition({m_window->getSize().x / 2.f + 54.f, m_window->getSize().y / 2.f});
    m_window->draw(textRestart);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
    {
        this->resetStatic();
        this->Initializare();
    }
}

void Joc::Victorie()
{
    sf::Font fontVictorie("Silkscreen\\slkscrb.ttf");
    sf::Text textVictorie(fontVictorie);
    textVictorie.setString("Ai castigat!!!");
    textVictorie.setCharacterSize(60);
    textVictorie.setFillColor(sf::Color::Black);
    textVictorie.setOutlineColor(sf::Color::White);
    textVictorie.setOutlineThickness(4.f);
    textVictorie.setOrigin({textVictorie.getGlobalBounds().size.x / 2.f, textVictorie.getGlobalBounds().size.y / 2.f});
    textVictorie.setPosition({m_window->getSize().x / 2.f, m_window->getSize().y / 2.f});
    
    m_window->draw(m_fundal->getSpriteVictorie());
    m_window->draw(textVictorie);
}

void Joc::Run()
{
    while (m_window->isOpen())
    {
        while (const std::optional event = m_window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            m_window->close();
        }

        m_window->clear(sf::Color::White);

        if(std::abs(m_jucator->getSprite().getGlobalBounds().position.x - 1300.f) < 30.f
           && m_jucator->getPlatformaCurenta() == m_platforme[5])
            m_victorie = 1;

        if(m_victorie == 1)
            this->Victorie();
        else
        {
            m_ajutor->animatieIdle();

            this->drawFundal();
            this->drawObiecte();
            
            if(m_jucator->esteLanga(m_inamic) && !m_inamic->getPasnic())
            {
                this->Restart();
                m_jucator->animatieIdle();
                m_inamic->animatieIdle();
                drawEntitate(m_window, m_ajutor);
                drawEntitate(m_window, m_inamic);
                drawEntitate(m_window, m_jucator);
                this->drawLumina();
            }
            else
            {
                m_jucator->Control();
                m_jucator->interactiuneObiecte();
                if(m_pasi[2] == 1 && m_pasi[4] == 0 && !m_inamic->esteLanga(m_obiecte[2]))
                    m_inamic->mergiLa(m_obiecte[2]);
                else
                    m_inamic->animatieIdle();
                if(m_pasi[3] == 1)
                    m_fundal->schimbaLumina();
                if(m_pasi[4] == 1 && !m_inamic->esteLanga(m_obiecte[6]))
                {
                    m_inamic->mergiLa(m_obiecte[6]);
                    if(m_inamic->esteLanga(m_obiecte[6]))
                    {
                        m_inamic->setPasnic(1);
                        m_inamic->animatieIdle();
                    }
                }
                else
                    if(m_inamic->esteLanga(m_obiecte[6]) && !m_inamic->isOnGround())
                        m_inamic->inCadere();
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    sf::Vector2f mousePos = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));

                    if(m_ajutor->getSprite().getGlobalBounds().contains(mousePos))
                    {
                        m_afHint = 1;
                        m_ceasHint->start();
                    }
                }
                if(m_afHint == 1)
                    this->afiseazaHint();

                drawEntitate(m_window, m_ajutor);
                drawEntitate(m_window, m_inamic);
                drawEntitate(m_window, m_jucator);
                this->drawLumina();
            }
        }
        m_window->display();
    }
}

Joc::~Joc()
{
    delete m_window;
    delete m_fundal;
    /*
    delete m_jucator;
    delete m_inamic;
    delete m_ajutor;
    */
    for(Obiect* obiect: m_obiecte)
        delete obiect;
}