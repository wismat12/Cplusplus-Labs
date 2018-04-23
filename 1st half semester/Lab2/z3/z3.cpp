#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void wypelnijlosowo(int **tab);
void znajdznajwieksze(int **tab, int &pierwsza, int &druga);

int main(int argv, char* arg[])
{
    int **tabliczka;
    int i, wys, szer, pierwsza, druga;

    cout << "Podaj iczbe wierszy nowej tablicy" << endl;
    cin >> wys;
    cout << "Podaj liczbe kolumn nowej tablicy" << endl;
    cin >> szer;

    tabliczka = new int * [wys];
    for(i=0;i<10;i++) tabliczka[i] = new int [szer];

    wypelnijlosowo(tabliczka);
    znajdznajwieksze(tabliczka, pierwsza, druga);

    cout << "Liczby w tablicy ktorych iloczyn da najwkieszy wynik to: " << pierwsza << "*" << druga << endl;

    for(i=0;i<10;i++) delete[] tabliczka[i];
    delete[] tabliczka;
  return 0;
}

void wypelnijlosowo(int **tab)
{
    int i,j;

    srand(time(NULL));

    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            tab[i][j] = rand();
}
void znajdznajwieksze(int **tab, int &pierwsza, int &druga)
{
    int i,j, tmp;

    pierwsza = tab[0][0];
    druga = pierwsza;
    tmp = druga;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {

            if(pierwsza <= tab[i][j])
            {
                tmp = pierwsza;
                pierwsza = tab[i][j];
                druga = tmp;
            }
        }
    }
}
