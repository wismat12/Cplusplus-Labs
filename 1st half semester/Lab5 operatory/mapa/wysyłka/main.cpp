#include <iostream>
#include"mapa.h"
using namespace std;

int main()
{
    string slowo = "kasia";

    //Podanie konstruktorowni sciezki do pliku
    Mapa mapka("input.txt");

    cout << "Program utworzyl: " << Mapa::Rozmiar_listy << " obiektow klasy Para. " << endl;


    if(mapka.sprawdz_czy_wiekszy(0,2))
    {
        cout << "-Tak!" << endl;
    }
    else
    {
        cout << "-Nie!" << endl;
    }
    if(mapka.sprawdz_czy_mniejszy(6,4))
    {
        cout << "-Tak!" << endl;
    }
    else
    {
        cout << "-Nie!" << endl;
    }
    if(mapka.sprawdz_czy_rowny(11,10))
    {
        cout << "-Tak!" << endl;
    }
    else
    {
        cout << "-Nie!" << endl;
    }

    int ilosc = mapka[slowo];
    cout << ilosc << endl;

    cout << endl << mapka;

    return 0;
}
