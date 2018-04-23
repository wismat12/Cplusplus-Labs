#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int N = 5;
int po[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int pi[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int los[8] = {0};

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

void dostep(int t[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                if((i + pi[k]) >= 0 && (i + pi[k]) < N && (j + po[k]) >= 0 && (j + po[k]) < N)
                    t[i][j]++;
            }
        }
    }
}

void spacer(int t[][N], int d[][N], int x, int y)
{
    int stop = 1, i = 1, nx, ny, px, py, pdost, ruch=0, losowy;
    t[x][y] = i;
     srand( time(NULL) );
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
        for(int k = 0; k < 8; k++)
        {
            px = x + po[k];
            py = y + pi[k];
            if(px >= 0 && px < N && py >= 0 && py < N && t[px][py] == 0)
            {
                if(d[px][py] == pdost)
                {
                    los[ruch] = k;
                    ruch++;
                }
            }
        }
         ruch--;
        if(ruch!=0)
        {
            losowy = los[rand() % (ruch)];
            nx = x + po[losowy];
            ny = y + pi[losowy];

         while(ruch!=0 && los[ruch]!=losowy)
        {
            px = x + po[los[ruch]];
            py = y + pi[los[ruch]];


         t[px][py]--;
        }
        }


        if(pdost < 1000)
        {
            x = nx;
            y = ny;
            i++;
            t[x][y] = i;

            wypisz(d);
            wypisz(t);
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
    int d[N][N];
    int t[N][N];

    zeruj(d);
    dostep(d);
    wypisz(d);
    zeruj(t);
    spacer(t, d, 0, 0);
    wypisz(t);


    return 0;
}
