#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "mapa.h"
#include "para.h"
#include <algorithm>
#include <list>
using namespace std;

int Mapa::Rozmiar_listy = 0;

bool IsOnlySpaces(string s)
{
    for(unsigned int i = 0;i < s.size();i++)
        if(s[i]!=' ') return false;

    return true;
}

bool cmp(Para a, Para b)
{
    return(a.GetAmount() > b.GetAmount());
}
//Implementacja

Mapa::Mapa(const Mapa & m)
{
    this->lista = m.lista;
}

void Mapa::take_word(string s)
{
    bool added = false;

    if(this->lista.size() == 0)
    {
        this->lista.push_back(Para(s));
    }
    else
    {
        for(list<Para>::iterator i = lista.begin(); i !=lista.end(); i++)
        {
            if(i->GetWord() == s)
            {
                (*i)++;
                added = true;
                break;
            }
        }
        if(!added)
        {
            this->lista.push_back(Para(s));
        }
    }
}
int Mapa::operator[](string s)
{
    cout << "Szukasz ilosci powtorzen slowa " << s << " : ";
    for(list<Para>::iterator i = lista.begin(); i !=lista.end(); i++)
        {
            if(i->GetWord() == s)
            {
               return i->GetAmount();
            }
        }
     return 0;
}
//Konstruktor ze sciezka do pliku txt
Mapa::Mapa(const char *path)
{
    string line;
    ifstream ifile(path);
    string str;

    unsigned int inext=0,position;

    while(!ifile.eof())
    {
        getline(ifile,line);
        inext = 0;

        while(inext != line.size() )
        {
            if((line[inext] == ',')||(line[inext] == ';')||(line[inext] == '\t')) line[inext] = ' ';
            inext++;
        }

        while((position = line.find(' ')) != std::string::npos)     //W przypadku nieskonczonej petli zamiast npos uzyc -1
        {
            str = line.substr(0, position);
            if(!IsOnlySpaces(str))
            this->take_word(str);

            line.erase(0, position + 1);
        }
        if(position==(std::string::npos))
        {
        if(!IsOnlySpaces(line))
           this->take_word(line);
        }
    }
    Mapa::Rozmiar_listy = lista.size();
}

ostream & operator<<(ostream & os, Mapa m)
{
    int counter = 20;

    m.lista.sort(cmp);

    cout << "Wypisanie listy obiektow para: (domyslnie do " << counter << ")" << endl;
    for(list<Para>::iterator i = m.lista.begin(); i !=m.lista.end(); i++)
    {
        if(counter-- == 0) break;
        os << i->GetWord() << " Znaleziono: " << i->GetAmount() << " razy!" << endl;
    }
    return os;
}
bool Mapa::sprawdz_czy_wiekszy(unsigned int nr_iteratora1,unsigned int nr_iteratora2)
{
    this->lista.sort(cmp);

    list<Para>::iterator i = this->lista.begin();
    list<Para>::iterator j = this->lista.begin();
    //advance(i,5); ustawienie iteratora i na 5 + 1 element
    advance(i,nr_iteratora1);
    advance(j,nr_iteratora2);

    if((*i) > (*j)) return true;
    else
       return false;
}
bool Mapa::sprawdz_czy_mniejszy(unsigned int nr_iteratora1,unsigned int nr_iteratora2)
{
    this->lista.sort(cmp);

    list<Para>::iterator i = this->lista.begin();
    list<Para>::iterator j = this->lista.begin();
    //advance(i,5); ustawienie iteratora i na 5 + 1 element
    advance(i,nr_iteratora1);
    advance(j,nr_iteratora2);

    if((*i) < (*j)) return true;
    else
       return false;
}
bool Mapa::sprawdz_czy_rowny(unsigned int nr_iteratora1,unsigned int nr_iteratora2)
{
    this->lista.sort(cmp);

    list<Para>::iterator i = this->lista.begin();
    list<Para>::iterator j = this->lista.begin();
    //advance(i,5); ustawienie iteratora i na 5 + 1 element
    advance(i,nr_iteratora1);
    advance(j,nr_iteratora2);

    if((*i) == (*j)) return true;
    else
       return false;
}

