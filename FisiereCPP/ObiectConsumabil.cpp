#include "..\\FisiereH\\Joc.h"

Obiect* ObiectConsumabil::clone() const
{
    return new ObiectConsumabil(*this);
}

void ObiectConsumabil::Interactioneaza()
{
    m_vizibil = 0;
}
void ObiectConsumabil::Afiseaza()
{
    m_vizibil = 1;
}
bool ObiectConsumabil::getVizibil()
{
    return m_vizibil;
}

void ObiectConsumabil::Aranjeaza()
{
    int k = 0;
    for(Obiect* obiect: Joc::m_obiecte)
    {
        if(auto* ob = dynamic_cast<ObiectConsumabil*>(obiect))
        {
            if(ob->getVizibil())
            {
                ob->setPosition({50.f, 50.f + k * 92.f});
                k++;
            }
        }
    }
}
