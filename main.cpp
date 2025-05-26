#include "FisiereH\\Joc.h"

int main()
{
    Joc* joc;
    joc = Joc::getInstanta();
    joc->Initializare();
    joc->Run();
    return 0;
}