#include <iostream>

using namespace std;

void wypelnij(int tab[][10]);
void wyswietln(int tab[][10]);

int main(int argv, char* arg[])
{
  //int **tabliczka;
  int i;
  int tabliczka[10][10];
  //tabliczka = new int * [10];
    //for(i=0;i<10;i++) tabliczka[i] = new int [10];


  wypelnij(tabliczka);
  wyswietln(&tabliczka[0][0]);

  return 0;
}

void wypelnij(int tab[][10])
{
    int i,j;

    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            tab[i][j] = (i+1)*(j+1);
}
void wyswietln(int *tab)
{
    int i,j;
    int *t = &tab;
    cout.flags(std::ios_base::left);
    for(i=0;i<10;i++){

        for(j=0;j<10;j++)
        {


            cout.width(6);
            cout << *t;
            t++;



            if(((j%9)==0)&&(j!=0)) cout << endl;


        }
    }



}
