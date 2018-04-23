#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "ksztalt.h"
#include "kolo.h"
#include "kwadrat.h"
#include "trojkat.h"

using namespace std;

int main()
{
    int list_size = 10;

    list<Ksztalt*> lista;

    srand(time(NULL));

    Kwadrat kwadrat;
    Kolo kolo;
    Trojkat trojkat;

    for(int i = 0;i < list_size;i++)
    {
        int losuj = rand() % 3;

        if(losuj == 1)
        {
            lista.push_back(&kwadrat);
            //Lista polimorficznych wskaznikow do klasy Ksztalt otrzymuje adres obiektow pochodnych
        }
        else
        {
            if(losuj == 2)
            {
                lista.push_back(&kolo);
            }
            else
            {
                lista.push_back(&trojkat);
            }
        }
    }
    for(list<Ksztalt*>::iterator i = lista.begin(); i !=lista.end(); i++)
        {
            //Defeferencja elementu listy i wywolanie metody wirtualnej rysuj
            (*i)->rysuj();
        }

    return 0;
}
