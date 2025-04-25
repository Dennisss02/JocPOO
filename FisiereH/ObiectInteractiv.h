#ifndef OBIECTINTERACTIV_H
#define OBIECTINTERACTIV_H

#include "Obiect.h"

class ObiectInteractiv: public Obiect
{
public:
    Obiect* clone() const;
    void setTextura(sf::Texture& textura);
    void Interactioneaza();
};

#endif