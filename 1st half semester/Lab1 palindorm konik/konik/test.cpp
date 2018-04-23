#include<iostream>

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
void aktualizuj(int x, int y, int dostepnosc[][N], int tablica[][N])
{
   // for(int i = 0; i < N; i++)
   // {
      //  for(int j = 0; j < N; j++)
       // {
       int i=x;
       int j=y;
            for(int k = 0; k < 8; k++)
            {
                if((tablica[i][j])!=0) dostepnosc[i][j]=0;
                if((((i + pi[k]) >= 0 && (i + pi[k]) < N && (j + po[k]) >= 0 && (j + po[k]) < N)&&(dostepnosc[i + pi[k]][j + po[k]]!=0)))
                  {

                   dostepnosc[i + pi[k]][j + po[k]]--;
                    cout<<"fake";
                  }
            }
        //}
    //}

}

void spacer(int t[][N], int d[][N], int x, int y)
{
    int stop = 1, i = 1, nx, ny, px, py, pdost;
    t[x][y] = i;


    while(stop)
    {
        pdost = 1000;
        for(int k = 0; k < 8; k++)
        {
            px = x + po[k];
            py = y + pi[k];
            if(px >= 0 && px < N && py >= 0 && py < N && t[px][py] == 0)
            {
                if(d[px][py] < pdost)
                {
                    pdost = d[px][py];
                    nx = px;
                    ny = py;
                }

            }
        }
        if(pdost < 1000)
        {
            aktualizuj(x,y,d,t);

            x = nx;
            y = ny;
            i++;
            t[x][y] = i;


            wypisz(t);
            wypisz(d);
            //cout << nx << " " << ny << " " << pdost << endl;
        }
        else
        {
            cout << endl << i << " " << nx << " " << ny << endl;
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
