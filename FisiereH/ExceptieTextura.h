#ifndef EXCEPTIETEXTURA_H
#define EXCEPTIETEXTURA_H

#include <iostream>
#include <exception>
#include <string>

class ExceptieTextura: public std::exception
{
private:
    std::string mesaj;
public:
    ExceptieTextura(const std::string& cale): mesaj("Nu s-a putut incarca textura " + cale){}
    const char* what() const noexcept
    {
        return mesaj.c_str();
    }
    void afiseazaEroare() const
    {
        std::cerr << mesaj.c_str();
    }
};

#endif