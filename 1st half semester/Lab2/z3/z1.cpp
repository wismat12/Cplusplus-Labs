#include <iostream>

using namespace std;

void wypelnij(int **tab, int szer, int wys);
void wyswietln(int **tab, int szer, int wys);

int main(int argv, char* arg[])
{

    cout << -1 << endl;

   /* int **tabliczka;
    int i, wys, szer, pierwsza, druga;

    cout << "Podaj iczbe wierszy nowej tablicy" << endl;
    cin >> wys;
    cout << "Podaj liczbe kolumn nowej tablicy" << endl;
    cin >> szer;

    tabliczka = new int * [wys];
    for(i=0;i<wys;i++) tabliczka[i] = new int [szer];


    wypelnij(tabliczka, szer, wys);
    wyswietln(tabliczka, szer, wys);*/

    return 0;
}

void wypelnij(int **tab, int szer, int wys)
{
    int i,j;

    for(i=0;i<wys;i++)
        for(j=0;j<szer;j++)
            tab[i][j] = (i+1)*(j+1);
}
void wyswietln(int **tab, int szer, int wys)
{
    int i,j;

    cout.flags(std::ios_base::left);
    for(i=0;i<wys;i++){

        for(j=0;j<szer;j++)
        {
            cout.width(5);
            cout << left << tab[i][j];

            if((j%(szer-1)==0)&&(j!=0))
                cout << endl;
        }

    }
}

