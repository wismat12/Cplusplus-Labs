#include <iostream>
#include "dtab.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    DTab Domyslna;
    DTab t;






    //DTab * Niedomyslna = new DTab(5);
    //TEST
    srand(time(NULL));

    for(int i = 0; i < 15; i++)
        Domyslna.add(sqrt(rand() % 50));
        //Domyslna.set(25,5);
    t = Domyslna;
//
    cout << Domyslna;
    Domyslna++;
    //Domyslna.set(25,5);
    cout << Domyslna;


    return 0;
}
