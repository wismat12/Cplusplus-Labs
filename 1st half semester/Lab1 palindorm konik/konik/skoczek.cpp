// Mateusz Wisniewski Czwartek 9:30
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const int N = 8;
int po[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int pi[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
//------------------
void zeruj(int t[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j ++)
        {
            t[i][j] = 0;
        }
    }
}

void wypisz(int t[][N])
{
    cout << endl;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j ++)
        {
            cout.width(3);
            cout << left << t[i][j];
        }
        cout << endl;
    }
}

void dostep(int dostepnosc[][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            for(int k = 0; k < 8; ++k)
            {
                if((i + pi[k]) >= 0 && (i + pi[k]) < N && (j + po[k]) >= 0 && (j + po[k]) < N)
                    dostepnosc[i][j]++;
            }
        }
    }
}

void aktualizuj(int i, int j, int dostepnosc[][N], int tablica[][N])
{
    for(int k = 0; k < 8; k++)
    {
        if((tablica[i][j])!=0) dostepnosc[i][j]=0;

        if((((i + pi[k]) >= 0 && (i + pi[k]) < N && (j + po[k]) >= 0 && (j + po[k]) < N)&&(dostepnosc[i + pi[k]][j + po[k]]!=0)))
        {
            dostepnosc[i + pi[k]][j + po[k]]--;
        }
    }
}

void spacer(int & i, int t[][N], int d[][N], int x, int y)
{
    int stop = 1, nx, ny, px, py, poziom_dostepu, startx, starty;
    t[x][y] = i;
    int mozliwosci[8][2];
    startx = x;
    starty = y;

    srand(time(NULL));

    while(stop)
    {
        poziom_dostepu = 1000;
        int ilosc_ruchow = 0, losowy = 0;

        for(int k = 0; k < 8; ++k)
        {
            px = x + pi[k];
            py = y + po[k];
            if(px >= 0 && px < N && py >= 0 && py < N && t[px][py] == 0)
            {
                if(d[px][py] < poziom_dostepu)
                {
                    poziom_dostepu = d[px][py];
                }
            }
        }
        for(int k = 0; k < 8; ++k)
        {
            px = x + pi[k];
            py = y + po[k];
            if(px >= 0 && px < N && py >= 0 && py < N && t[px][py] == 0)
            {
                if(d[px][py] == poziom_dostepu)
                {
                    mozliwosci[ilosc_ruchow][0] = px;
                    mozliwosci[ilosc_ruchow][1] = py;
                    ilosc_ruchow++;
                }
            }
        }
        if(poziom_dostepu < 1000)
        {
            aktualizuj(x,y,d,t);

            losowy = rand() % ilosc_ruchow;

            x = mozliwosci[losowy][0];
            y = mozliwosci[losowy][1];
            i++;
            t[x][y] = i;
        }
        else
        {
            if(i==64)  cout << endl << "Wykonano ruchow: " << i << " Punkt Startowy w " << startx << " " << starty << " " << "//Ostatni punkt w: " << " " << x << " " << y << endl;
            break;
        }
    }


}

int main()
{
    int dostepnosc[N][N];
    int t[N][N];
    int licznik = 1;
    int z,x;

    zeruj(dostepnosc);
    dostep(dostepnosc);
    cout << "Macierz dostepu" << endl;
    wypisz(dostepnosc);
    zeruj(t);
    for(z = 0;z < N; ++z)
        for(x = 0;x < N; ++x)
        {
            spacer(licznik, t, dostepnosc, z, x);
            if (licznik == 64)
                wypisz(t);

            Sleep(1000);
            zeruj(dostepnosc);
            dostep(dostepnosc);
            zeruj(t);
            licznik = 1;
        }
    return 0;
}
