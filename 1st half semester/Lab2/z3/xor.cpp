#include <cstdio>
#include <cstring>

using namespace std;

bool xorek(const char * plikXorowany, const char *plikWyjsciowy, const char *klucz)
{
    FILE *plik = fopen(plikXorowany, "rb");
    FILE *zaszyfrowany = fopen(plikWyjsciowy, "wb");

    if (plik!=NULL && zaszyfrowany!=NULL)
    {
        //udane otwarcie pliku do zaszyfrowania i wyjsciowego
        int length = strlen(klucz);
        int znak, xorChar;
        int mod = 0;

        //szyfrowanie XOR znak po znaku
        do
        {
            if (mod >= length)
                mod=0;
            znak = fgetc(plik);
            xorChar = znak^klucz[mod];
            mod++;
            if (znak != EOF)
                fputc(xorChar, zaszyfrowany);
        }
        while (znak != EOF);

        //zapisywanie plikow (zamykanie)
        if (fclose(zaszyfrowany)==0 && fclose(plik)==0)
            return true;
        else
            return false;

    }
    else
        return false;
}

int main (int argc, char *argv[])
{
    //obsluga programu za pomoca argumentow
    if (argc>=3)
    {
        if (xorek(argv[1], argv[2], argv[3]))
            printf("Poprawnie zaszyfrowano plik %s kluczem %s!", argv[1], argv[3]);
        else
            printf("Niezdefiniowany blad!");

    }
    else
    {
        //gdy za mala liczba argumentow
        printf("\nUzycie: \n%s <nazwa_pliku> <plik_wynikowy> <klucz>", argv[0]);
    }
    return 0;
}
//http://haker.edu.pl/2015/10/07/szyfrowanie-plikow-xor-w-c/
