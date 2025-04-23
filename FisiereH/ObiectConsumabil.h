#ifndef OBIECTCONSUMABIL_H
#define OBIECTCONSUMABIL_H

#include "Obiect.h"

class ObiectConsumabil: public Obiect
{
private:
    bool m_vizibil = 0;
public:
    void Interactioneaza();
    void Afiseaza();
    bool getVizibil();
};

#endif