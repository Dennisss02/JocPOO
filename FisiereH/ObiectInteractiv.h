#ifndef OBIECTINTERACTIV_H
#define OBIECTINTERACTIV_H

#include "Obiect.h"

class ObiectInteractiv: public Obiect
{
public:
    void setTextura(sf::Texture& textura);
    void Interactioneaza();
};

#endif