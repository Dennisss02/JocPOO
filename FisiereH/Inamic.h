#ifndef INAMIC_H
#define INAMIC_H

#include "Animal.h"
#include "ObiectInteractiv.h"

class Inamic: public Animal
{
private:
    int m_frameMers;
    float m_timpAnimatieMers;
    float m_viteza;
    bool m_onGround;
    float m_velocity;
    sf::FloatRect m_platformaCurenta;
    bool m_pasnic;
public:
    Inamic();
    void animatieMers();
    void setViteza(float viteza);
    void setPlatforma(sf::FloatRect platforma);
    bool intersectieX(sf::FloatRect platforma);
    bool intersectieY(sf::FloatRect platforma);
    void onGround();
    bool esteLanga(Obiect* obiect);
    void mergiLa(Obiect* obiect);
    bool getPasnic();
    void setPasnic(bool pasnic);
};

#endif