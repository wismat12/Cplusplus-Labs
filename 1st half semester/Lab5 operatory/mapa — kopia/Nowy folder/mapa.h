#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include <list>
#include <string>
#include"para.h"

using namespace std;

class Mapa
{
private:
    list <Para> lista;

public:
    Mapa(const Mapa &);
    Mapa(const char *);
    void print();
    void take_word(string);

    int operator[](string);
    friend ostream & operator<<(ostream &, Mapa);

};



#endif // MAPA_H_INCLUDED
