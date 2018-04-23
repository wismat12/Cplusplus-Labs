// Mateusz Wiœniewski Czwartek 9:30
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

bool palindrom(char *bf);

int main(int argv, char* arg[])
{
    char bufor[100];
    int i, choice;
    bool check;

    do{
        cout << "Zatwierdz enterem 1 - by wprowadzic zdanie i sprawdzic czy jest palindromem " << endl << "2 - Wyjdz z programu" << endl;
        cin >> choice;
        system("cls");
        cin.get();
        if(choice!=2)
        {
            cout << "Podaj zdanie" << endl;
            cin.getline(bufor,100);
            check = palindrom(bufor);
            if (check==true) cout << bufor << " Jest palindromem" << endl;
                else cout << bufor << " Nie jest palindromem!" << endl;
        }
    }while(choice!=2);

    return 0;
}
bool palindrom(char *bf)
{
    char nowy[100];
    int len, i, j=0, g=0, ascii;

    len = strlen(bf);

    for(i=0;i<len;i++)
    {

        ascii = (int)(bf[i]);

        if(ascii!=32)               //32-spacja
        {

            if(ascii <= 90)
                {
                  nowy[j] = (char)(ascii+32);
                }
                else
                {
                  nowy[j] = (char)(ascii);
                }
            j++;
        }
        nowy[j] = '\0';
    }
    for(g=0;g<j-1;g++)
    if(nowy[g]!=nowy[j - 1 - g]) return false;

    return true;
}

