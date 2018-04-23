/*
Problek konika (skoczka) szachowego
www.algorytm.org
Adam Mika (c) 2008

Algorytm podaje pierwsze dopuszczalne rozwi¹zanie problemu dla kolejnych punktów
startowych pod warunkiem, ¿e takie rozwi¹zanie istnieje.
*/


#include <iostream>

using namespace std;

bool ruch(int** tab, const int& N, int wariant, int x, int y, int& nx, int& ny)
{
switch (wariant) {
case 1:
nx = x+1;
ny = y-2;
break;
case 2:
nx = x+2;
ny = y-1;
break;
case 3:
nx = x+2;
ny = y+1;
break;
case 4:
nx = x+1;
ny = y+2;
break;
case 5:
nx = x-1;
ny = y+2;
break;
case 6:
nx = x-2;
ny = y+1;
break;
case 7:
nx = x-2;
ny = y-1;
break;
case 8:
nx = x-1;
ny = y-2;
break;
}
if (0<=nx && nx<N && 0<=ny && ny<N && tab[nx][ny]==0)
return true;
return false;
}

bool skoczek(int** tab, const int& n, int x, int y, int ktory)
{
int nx, ny, w;

tab[x][y] = ktory;

if(ktory == n*n)
{
for(int i=0 ; i<n ; i++)
{
for(int j=0 ; j<n ; j++)
cout<<tab[j][i]<<" ";
cout<<endl;
}
return 1;
}
else
{
for(w=1 ; w<9 ; w++)
if(ruch(tab, n, w, x, y, nx, ny) == true)
if (skoczek(tab, n, nx, ny, ktory+1) == true)
return true;
tab[x][y] = 0;
}

return false;
}

void clearTab(int** tab, const int& n)
{
for(int i=0 ; i<n ; i++)
for(int j=0 ; j<n ; j++)
tab[i][j] = 0;
}

int main()
{
const int max = 8;   //rozmiar problemu - wymiar szachownicy
int** tab = new int* [max];
for(int i=0 ; i<max ; i++)
tab[i] = new int[max];

for(int i=0 ; i<max ; i++)
for(int j=0 ; j<max ; j++)
{
clearTab(tab, max);
cout<<"\n(i,j)= "<<i<<", "<<j<<"\n";
skoczek(tab, max, i, j, 1);
}


//egetchar();
return 0;
}
