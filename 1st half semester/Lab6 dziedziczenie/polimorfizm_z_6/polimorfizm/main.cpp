#include <iostream>
#include "klasy.h"

using namespace std;

int main()
{
    UmowaPraca umowapraca(2000);
    UmowaDzielo umowadzielo(2000);

    Pracownik p("Raz","Dwa","333", &umowapraca);
    Pracownik c("Trzy","Cztery","333", &umowadzielo);

    cout << p << c;

    return 0;
}
