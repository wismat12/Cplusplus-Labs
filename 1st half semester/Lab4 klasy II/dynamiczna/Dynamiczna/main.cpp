#include <iostream>
#include "dtab.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{

    DTab test;


    DTab test2 = test.wypelniona(5);
    cout << endl;

    test2.set(34,9);
    test2.print();




/*    test = test.wypelniona(5);
    test.print();
    test.add(32);
    test.set(88,5);
    test.print();*/
  /*DTab Domyslna;
    DTab * Niedomyslna = new DTab(5);

    srand(time(NULL));


    for(int i = 0; i < 16; i++)
        Domyslna.add(sqrt(rand() % 50));
        Domyslna.set(25,5);
    Domyslna.print();

    for(int i = 0; i < 16; i++)
       Niedomyslna->add(sqrt(rand() % 50));
    Niedomyslna->print();


   delete Niedomyslna;*/


    return 0;
}
