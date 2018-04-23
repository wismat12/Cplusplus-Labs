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

    static int Rozmiar_listy;

    bool sprawdz_czy_wiekszy(unsigned int nr_iteratora1,unsigned int nr_iteratora2);
    bool sprawdz_czy_mniejszy(unsigned int nr_iteratora1,unsigned int nr_iteratora2);
    bool sprawdz_czy_rowny(unsigned int nr_iteratora1,unsigned int nr_iteratora2);

    int operator[](string);
    friend ostream & operator<<(ostream &, Mapa);
};



#endif // MAPA_H_INCLUDED
