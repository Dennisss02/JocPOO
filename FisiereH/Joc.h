#ifndef JOC_H
#define JOC_H

#include <SFML/Graphics.hpp>
#include "Jucator.h"
#include "Inamic.h"
#include "Ajutor.h"
#include "Fundal.h"
#include "ObiectInteractiv.h"
#include "ObiectConsumabil.h"
#include "ExceptieTextura.h"
#include "Entitate.h"

class Joc
{
private:
    static Joc* Instanta;

    sf::RenderWindow* m_window;
    Fundal* m_fundal;
    Entitate<Jucator> m_jucator;
    Entitate<Inamic> m_inamic;
    Entitate<Ajutor> m_ajutor;
    static std::vector<sf::FloatRect> m_platforme;
    static std::vector<Obiect*> m_obiecte;
    static std::vector<bool> m_pasi;
    sf::Clock* m_ceasHint;
    bool m_afHint = 0;
    bool m_victorie = 0;

    Joc();
public:
    friend class Jucator;
    friend class Inamic;
    friend class Ajutor;

    friend class ObiectConsumabil;

    Joc(const Joc&) = delete;
    Joc& operator=(const Joc&) = delete;
    static Joc* getInstanta();

    void initWindow();
    void initFundal();
    void initPlatforme();
    void initJucator();
    void initInamic();
    void initAjutor();
    inline void adaugaObiectInteractiv(std::string caleImagine);
    inline void adaugaObiectConsumabil(std::string caleImagine);
    void initObiecte();
    void Initializare();

    template<class T>
    friend void drawEntitate(sf::RenderWindow* window, T ob);

    inline void drawFundal();
    /*
    inline void drawJucator();
    inline void drawInamic();
    inline void drawAjutor();
    */
    void drawObiecte();
    inline void drawLumina();

    void afiseazaHint();

    static void resetStatic();
    void Restart();

    void Victorie();

    void Run();

    ~Joc();
};

#endif