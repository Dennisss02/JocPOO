#ifndef ENTITATE_H
#define ENTITATE_H

#include <SFML/Graphics.hpp>
#include <vector>

template<class T>
class Entitate
{
private:
    T* m_obiect;
public:
    Entitate()
    {
        m_obiect = new T();
    }
    Entitate(T* ob): m_obiect(ob) {}
    
    Entitate(const Entitate& ob)
    {
        this->m_obiect = new T(*ob.m_obiect);
    }

    T* operator->() const {
    return m_obiect;
    }
    operator T*() const
    {
        return m_obiect;
    }

    ~Entitate()
    {
        delete m_obiect;
    }
};

#endif