#include<iostream>

using namespace std;

const int N = 8;
int po[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int pi[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void zeruj(int t[][N], int & ruch)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j ++)
        {
            t[i][j] = 0;
        }
    }
    ruch = 0;
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

void dostepplus(int t[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                if((i + pi[k]) >= 0 && (i + pi[k]) < N && (j + po[k]) >= 0 && (j + po[k]) < N )
                    t[i][j]++;
            }
        }
    }
}
void dostepminus(int t[][N], int tablica[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                if((i + pi[k]) >= 0 && (i + pi[k]) < N && (j + po[k]) >= 0 && (j + po[k]) < N && (tablica!=0))
                    t[i][j]--;
            }
        }
    }
}


void spacer(int t[][N], int d[][N], int x, int y, int & ruch)
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
            x = nx;
            y = ny;
            i++;
            t[x][y] = i;
            ruch++;
            dostepminus(t,d);
            //cout << nx << " " << ny << " " << pdost << endl;
        }
        else
        {
           // cout << endl << i << " " << nx << " " << ny << endl;
            break;
        }
    }


}

int main()
{
    int d[N][N];
    int t[N][N];
    int ruchy;

    zeruj(d, ruchy);
    dostepplus(d   );
    wypisz(d);
    zeruj(t, ruchy);
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            spacer(t, d, i, j, ruchy);
            cout << ruchy << " ";
            if(ruchy==N*N) wypisz(t);
            zeruj(t, ruchy);
        }



    return 0;
}
