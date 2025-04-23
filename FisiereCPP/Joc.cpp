#include "..\\FisiereH\\Joc.h"

std::vector<sf::FloatRect> Joc::m_platforme;
std::vector<Obiect*> Joc::m_obiecte;
std::vector<bool> Joc::m_pasi(5, 0);

Joc::Joc()
{
    m_window = new sf::RenderWindow(sf::VideoMode({(unsigned int)1496, (unsigned int)850}), "Goana dupa pliculete!");
    
    m_fundal = new Fundal();

    m_jucator = new Jucator();
    m_inamic = new Inamic();
    m_ajutor = new Ajutor();
}

void Joc::initWindow()
{
    m_window->setFramerateLimit(60);
    m_window->setVerticalSyncEnabled(false);
}
void Joc::initFundal()
{
    sf::Texture texturaFundal("pictures\\Fundal.png");
    sf::Texture texturaLumina("pictures\\Lumina.png");
    m_fundal->setSpriteFundal(texturaFundal);
    m_fundal->setSpriteLumina(texturaLumina);
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
    sf::Texture texturaJucator("pictures\\Miti.png");
    m_jucator->setTextura(texturaJucator);
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
    sf::Texture texturaInamic("pictures\\Badi.png");
    m_inamic->setTextura(texturaInamic);
    m_inamic->Initializare();
    m_inamic->setPosition({1100.f, 210.f});
    m_inamic->setOrientare(0);
    m_inamic->setViteza(4.f);
    m_inamic->setPlatforma(m_platforme[5]);
    m_inamic->onGround();
}
void Joc::initAjutor()
{
    sf::Texture texturaAjutor("pictures\\Flafi.png");
    m_ajutor->setTextura(texturaAjutor);
    m_ajutor->Initializare();
    m_ajutor->setPosition({1092.f, 475.f});
}
void Joc::adaugaObiectInteractiv(std::string caleImagine)
{
    sf::Vector2f scale = {(float)m_window->getSize().x / m_fundal->getX(), 
                          (float)m_window->getSize().y / m_fundal->getY()};
    
    sf::Texture textura(caleImagine);
    m_obiecte.push_back(new ObiectInteractiv());
    int n = m_obiecte.size() - 1;
    m_obiecte[n]->setTextura(textura);
    m_obiecte[n]->setScale(scale);
}
void Joc::adaugaObiectConsumabil(std::string caleImagine)
{
    sf::Vector2f scale = {(float)m_window->getSize().x / m_fundal->getX(), 
                          (float)m_window->getSize().y / m_fundal->getY()};
    
    sf::Texture textura(caleImagine);
    m_obiecte.push_back(new ObiectConsumabil());
    int n = m_obiecte.size() - 1;
    m_obiecte[n]->setTextura(textura);
    m_obiecte[n]->setScale(scale);
    sf::FloatRect obBounds = m_obiecte[n]->getSprite().getGlobalBounds();
    m_obiecte[n]->setOrigin({128.f, 128.f});
    //m_obiecte[n]->setPosition({50.f, 50.f + Obiect::m_cntInventar * 92.f});
    m_obiecte[n]->setPosition({50.f, 50.f});
    Obiect::m_cntInventar++;
}
void Joc::initObiecte()
{
    this->adaugaObiectInteractiv("pictures\\Cutii.png");
    m_obiecte[0]->setPosition({502.f, 664.f});
    this->adaugaObiectInteractiv("pictures\\Trapa.png");
    m_obiecte[1]->setPosition({1254.f, 416.f});
    this->adaugaObiectInteractiv("pictures\\Vaza.png");
    m_obiecte[2]->setPosition({504.f, 390.f});
    this->adaugaObiectInteractiv("pictures\\Cufar.png");
    m_obiecte[3]->setPosition({789.f, 729.f});

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
void Joc::drawObiecte()
{
    for(Obiect* obiect: m_obiecte)
    {
        if(auto* ob = dynamic_cast<ObiectConsumabil*>(obiect))
            if(ob->getVizibil() == 0)
                continue;
        m_window->draw(obiect->getSprite());
    }
}
void Joc::drawLumina()
{
    m_window->draw(m_fundal->getSpriteLumina());
}

void Joc::Restart()
{
    sf::Font fontRestart("Silkscreen\\slkscr.ttf");
    sf::Text textRestart(fontRestart);
    textRestart.setString("Ai pierdut... :(");
    textRestart.setCharacterSize(60);
    textRestart.setFillColor(sf::Color::Black);
    textRestart.setStyle(sf::Text::Bold);
    textRestart.setOutlineColor(sf::Color::White);
    textRestart.setOutlineThickness(4.f);
    textRestart.setOrigin({textRestart.getGlobalBounds().size.x / 2.f, textRestart.getGlobalBounds().size.y / 2.f});
    textRestart.setPosition({m_window->getSize().x / 2.f + 54.f, m_window->getSize().y / 2.f});
    m_window->draw(textRestart);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
    {
        m_platforme.clear();
        m_obiecte.clear();
        m_pasi.clear();
        m_pasi.resize(5, 0);
        Obiect::m_cntInventar = 0;
        this->Initializare();
    }
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

        m_ajutor->animatieIdle();

        m_window->clear(sf::Color::White);
        this->drawFundal();
        this->drawObiecte();
        this->drawAjutor();
        this->drawInamic();
        this->drawJucator();
        this->drawLumina();
        if(m_jucator->esteLanga(m_inamic) && !m_inamic->getPasnic())
            this->Restart();
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
        }
        m_window->display();
    }
}

Joc::~Joc()
{
    delete m_window;
    delete m_fundal;
    delete m_jucator;
    delete m_inamic;
    delete m_ajutor;
    for(Obiect* obiect: m_obiecte)
        delete obiect;
}