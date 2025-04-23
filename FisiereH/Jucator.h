#ifndef JUCATOR_H
#define JUCATOR_H

#include "Animal.h"
#include "ObiectInteractiv.h"

class Jucator: public Animal
{
private:
    int m_frameMers;
    float m_timpAnimatieMers;
    float m_viteza;
    bool m_onGround;
    float m_velocity;
    sf::FloatRect m_platformaCurenta;
public:
    Jucator();
    void animatieMers();
    void animatiePerete();
    void animatieSalt();
    void onGround();
    void Salt();
    void Control();
    void setViteza(float viteza);
    void setVelocity(float velocity);
    void setPlatforma(sf::FloatRect platforma);
    bool intersectieX(sf::FloatRect platforma);
    bool intersectieY(sf::FloatRect platforma);
    void coliziuneTop(sf::FloatRect platforma);
    bool esteLanga(Obiect* obiect);
    bool esteLanga(Animal* animal);
    void interactiuneObiecte();
};

#endif