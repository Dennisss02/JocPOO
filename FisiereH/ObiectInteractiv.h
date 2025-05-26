#ifndef OBIECTINTERACTIV_H
#define OBIECTINTERACTIV_H

#include "Obiect.h"

class ObiectInteractiv: public Obiect
{
public:
    Obiect* clone() const;
    void setTextura(sf::Texture& textura);
    void Interactioneaza();

    static ObiectInteractiv* creeazaCutie(sf::Vector2f pozitie);
    static ObiectInteractiv* creeazaTrapa(sf::Vector2f pozitie);
    static ObiectInteractiv* creeazaVaza(sf::Vector2f pozitie);
    static ObiectInteractiv* creeazaCufar(sf::Vector2f pozitie);
};

#endif