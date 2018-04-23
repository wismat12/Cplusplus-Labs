#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argv, char* arg[]){



    ifstream plikwejscia(arg[1]);
    ofstream plikwyjscia(arg[2], ios_base::in | ios_base::trunc);


    char word[64];
    char line[256];
    char polibiusz[5][5];
    int dodaj=0;
    int lenword;
    string szyfr;
    int NR, ascii, i, j;
    char wybor;

    for(i=0;i < 5; i++)
        for(j=0;j < 5;j++)
        {
            if((i*5 + j)==9)    dodaj++;                     //ascii 73==74  I=J
            polibiusz[i][j] = (char)(65+i*5+j+dodaj);
        }

    if(!plikwejscia)
    cout << "Nie mo¿na otworzyæ pliku!" << endl;

    switch(arg[3][0])
    {
        case '1':
            while(plikwejscia >> word)
            {
                for(NR=0; NR < strlen(word); NR++)
                    for(i=0;i < 5; i++)
                        for(j=0;j < 5;j++)
                        {
                            ascii = (int)(word[NR]);
                            if(ascii>=97) ascii =  ascii - 32;
                            if(ascii==74) ascii=73;
                                                                       //ascii 73==74  I=J
                            if(((int)(polibiusz[i][j])) == ascii) szyfr = szyfr + (char)(i+49) + (char)(j+49) + " ";

                        }
                plikwyjscia << szyfr;
                szyfr.clear();
            }
        break;

        case '0':
            while(plikwejscia >> word)
            {
                    for(i=0;i < 5; i++)
                        for(j=0;j < 5;j++)
                            if(((int)(word[0])-49==i)&&((int)(word[1])-49==j))  plikwyjscia << polibiusz[i][j];                                                                        //ascii 73==74  I=J

                plikwyjscia << szyfr;
                szyfr.clear();
            }
        break;
        deafult:
            cout << "Zly argument!!!" << endl;

    }

  plikwejscia.close();
  plikwyjscia.close();
  return 0;
}
