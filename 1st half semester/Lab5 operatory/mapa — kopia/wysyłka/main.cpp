#include <iostream>
#include"mapa.h"
using namespace std;

int main()
{
    string slowo = "agh";

    //Podanie konstruktorowni sciezki do pliku
    Mapa mapka("input.txt");

    cout << "Program utworzyl: " << Mapa::Rozmiar_listy << " obiektow klasy Para. " << endl;


    if(mapka.sprawdz_czy_wiekszy(0,1))
    {
        cout << "-Tak!" << endl;
    }
    else
    {
        cout << "-Nie!" << endl;
    }
    if(mapka.sprawdz_czy_mniejszy(4,3))
    {
        cout << "-Tak!" << endl;
    }
    else
    {
        cout << "-Nie!" << endl;
    }
    if(mapka.sprawdz_czy_rowny(0,5))
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
