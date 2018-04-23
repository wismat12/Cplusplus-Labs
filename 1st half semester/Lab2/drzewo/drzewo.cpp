#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
using namespace std;
typedef struct KRAWEDZ krawedz;
struct KRAWEDZ
{
    int a, b;
    int waga;
    bool skreslona;
};
int szukaj_krav(krawedz *tab_krav,int liczba_krawedzi, int *tab_krav_do_wyboru)
{
    int losowa, i;
    krawedz tmp;
        //szukanie krawedzi o takich samych wagach
    int numer_krav;
        //szukanie startowej krav
    for(i=0;i<liczba_krawedzi;i++) if(tab_krav[i].skreslona==false) tab_krav[i] = tmp;

    numer_krav = 0;
    for(i=0;i<liczba_krawedzi;i++)
    {
        if((tab_krav[i].waga==tmp.waga)&&(tab_krav[i].skreslona==false))
        {
            tab_krav_do_wyboru[numer_krav] = i;
            numer_krav++;
        }
    }
    losowa = rand() % numer_krav;
    return tab_krav_do_wyboru[losowa];
}
bool sprawdz_cykl(int poczatek, int nowy_punkt, krawedz *tab_krav, int **nowe_drzewo, int liczba_krawedzi)
{
    if(nowy_punkt==poczatek) return true;
    for(int i=0;i<liczba_krawedzi; i++)
       if((nowe_drzewo[nowy_punkt][i]!=0)&&(nowy_punkt!=i)) sprawdz_cykl(poczatek, i, tab_krav, nowe_drzewo, liczba_krawedzi);
    return false;
}
int main()
{
    int liczba_wierzcholkow, liczba_krawedzi=0;
    //int **wagi_krav;
    krawedz *tab_krav, tmp;
    bool stop=false;
    int i, j, p, n, pion=0, poziom=0, numer_krav=0, index_do_wyboru=0, losowa,*tab_krav_do_wyboru, znaleziona;

    int wagi_krav[7][7] = {{0,16,12,21,0,0,0},{16,0,0,17,20,0,0},
                          {12,0,0,28,0,31,0},{21,17,28,0,18,19,23},
                          {0,20,0,18,0,0,11},{0,0,31,19,0,0,27},
                          {0,0,0,23,11,27,0}};

    int nowe_drzewo[7][7] = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0},{0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0},{0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0}};

    ifstream myfile("file.txt");
    char word[64];
    srand(time(NULL));
    /*if(!myfile)
    {
        cout << "Nie mo¿na otworzyæ pliku!" << endl;
        return -1;
    }*/
    //myfile >> liczba_wierzcholkow;
    liczba_wierzcholkow = 7;
    //liczba_wierzcholkow = ((int)(word[0])-48) * 10 + ((int)(word[1])-48);
    /*wagi_krav = new int * [liczba_wierzcholkow];
    for(i=0;1<liczba_wierzcholkow;i++)  wagi_krav[i] = new  int [liczba_wierzcholkow];
        */

    while(pion < liczba_wierzcholkow)
    {
        poziom = pion;
        while(++poziom < liczba_wierzcholkow)
        {
            if(wagi_krav[pion][poziom]!=0)  liczba_krawedzi++;
        }
        pion++;
    }
    tab_krav = new krawedz [liczba_krawedzi];
    tab_krav_do_wyboru = new int [liczba_krawedzi];
    pion=0;
    poziom=0;
    i=0;
    while(pion < liczba_wierzcholkow)
    {
        poziom = pion;
        while(++poziom < liczba_wierzcholkow)
        {
            if(wagi_krav[pion][poziom]!=0)
            {
                tab_krav[i].a = pion;
                tab_krav[i].b = poziom;
                tab_krav[i].waga = wagi_krav[pion][poziom];
                tab_krav[i].skreslona = false;
                i++;
            }
        }
        pion++;
    }
    for(i=0;i<liczba_krawedzi - 1;i++) //Sortowanie krawedzi
        for(j=0;j<liczba_krawedzi - i;j++)
        {
            if(tab_krav[j].waga > tab_krav[j+1].waga)
            {
              tmp = tab_krav[j+1];
              tab_krav[j+1] = tab_krav[j];
              tab_krav[j]= tmp;
            }
        }
    //w petli
    while(!stop)
    {
        stop = true;
        for(i=0;i<liczba_krawedzi;i++)  if(tab_krav[i].skreslona==false) stop = false;
        if(!stop)
        {
            znaleziona = szukaj_krav(tab_krav, liczba_krawedzi, tab_krav_do_wyboru);
            tab_krav[znaleziona].skreslona = true;
            if(sprawdz_cykl(tab_krav[znaleziona].a, tab_krav[znaleziona].b)==false)
            {
                nowe_drzewo[tab_krav[znaleziona].a][tab_krav[znaleziona].b] = tab_krav[znaleziona].waga;
                nowe_drzewo[tab_krav[znaleziona].b][tab_krav[znaleziona].a] = tab_krav[znaleziona].waga;

            }
        }
    }





     for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            cout.width(3);
            cout << left << wagi_krav[i][j];
        }
    cout << endl;
     }
     for(i=0;i<liczba_krawedzi;i++)
        cout << tab_krav[i].a << " " << tab_krav[i].b<< endl;





  //myfile.close();
    return 0;
}
