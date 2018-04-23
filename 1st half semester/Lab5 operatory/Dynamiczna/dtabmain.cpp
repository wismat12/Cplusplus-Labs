#include <iostream>
#include "dtab.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    DTab Domyslna;
    DTab * Niedomyslna = new DTab(5);
    //TEST
    srand(time(NULL));

    for(int i = 0; i < 16; i++)
        Domyslna.add(sqrt(rand() % 50));
        Domyslna.set(25,5);
    Domyslna.print();

    for(int i = 0; i < 16; i++)
        Niedomyslna->add(sqrt(rand() % 50));
    Niedomyslna->print();


    delete Niedomyslna;


    return 0;
}
