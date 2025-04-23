#include "..\\FisiereH\\ObiectConsumabil.h"

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
