#include<iostream>
#include <cstdlib>
#include <ctime>
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
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < 8; k++)
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

void spacer(int t[][N], int d[][N], int x, int y)
{
    int stop = 1, i = 1, nx, ny, px, py, poziom_dostepu;
    t[x][y] = i;
    int mozliwosci[8][2];

    srand(time(NULL));

    while(stop)
    {
        poziom_dostepu = 1000;
        int ilosc_ruchow = 0, losowy = 0;
        for(int k = 0; k < 8; k++)
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
        for(int k = 0; k < 8; k++)
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




        if(poziom_dostepu0 < 1000)
        {
            aktualizuj(x,y,d,t);

            losowy = rand() % ilosc_ruchow;

            x = mozliwosci[losowy][0];
            y = mozliwosci[losowy][1];
            i++;
            t[x][y] = i;


            wypisz(t);
            wypisz(d);
        }
        else
        {
            cout << endl << i << " " << x << " " << y << endl;
            break;
        }
    }


}

int main()
{
    int dostepnosc[N][N];
    int t[N][N];

    zeruj(dostepnosc);
    dostep(dostepnosc);
    wypisz(dostepnosc);
    zeruj(t);
    spacer(t, dostepnosc, 0, 0);
    wypisz(t);


    return 0;
}
