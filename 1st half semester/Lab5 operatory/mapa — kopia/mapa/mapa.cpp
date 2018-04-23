#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "mapa.h"
#include "para.h"
#include <algorithm>
#include <list>
using namespace std;
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
/*void clean(string & s)
{
    string str;
    unsigned int iprev=0, inext=0;
    bool errors=false;
    while(inext != s.size() )
    {
        if((s[inext] == ',')||(s[inext] == ';')||(s[inext] == '\n')){
        errors = true;

        str = s.substr(iprev, inext);
        iprev = inext;

        this->lista.push_back(str);
        }
        if(errors == false) this->lista.push_back(s);
        inext++;
    }

}*/
Mapa::Mapa(const Mapa & m)
{
    this->lista = m.lista;
}
void Mapa::take_word(string s)
{
    bool added = false;
    Para *tmp;
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
                ++(*i);
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
    cout << "Szukasz ilosci powtorzen slowa " << s << endl;
    for(list<Para>::iterator i = lista.begin(); i !=lista.end(); i++)
        {
            if(i->GetWord() == s)
            {
               return i->GetAmount();
            }
        }
     return 0;
}
Mapa::Mapa(const char *path)
{

    string line;
    ifstream ifile(path);
    string str;

    unsigned int inext=0,position;

   //ool errors=false;

    while(!ifile.eof())
    {
        getline(ifile,line);
        inext = 0;

        while(inext != line.size() )
        {
            if((line[inext] == ',')||(line[inext] == ';')||(line[inext] == '\t')) line[inext] = ' ';
            inext++;
        }

        while((position = line.find(' ')) != std::string::npos)
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




    //cout << line <<endl;}

    /*while(ifile >> t)
    {
        iprev=0;
        inext=0;
        errors=false;
        do
        {
            if((t[inext] == ',')||(t[inext] == ';')||(t[inext] == '\n')){
                errors = true;

                str = t.substr(iprev, inext);
                iprev = inext;

                this->lista.push_back(str);
            }
            if(errors == false)
            {
                this->lista.push_back(t);
                break;
            }
            inext++;
        }while(inext != t.size() );
            //t.erase(remove_if(t.begin(), t.end(), IsWronChar), t.end());
            //clean(t);
            //this->lista.push_back(t);
    }*/

}
void Mapa::print()
{
    //for(list<Para>::iterator i = lista.begin(); i !=lista.end(); i++)
      // i->print();


}
ostream & operator<<(ostream & os, Mapa m)
{
    m.lista.sort(cmp);

    for(list<Para>::iterator i = m.lista.begin(); i !=m.lista.end(); i++)
    os << i->GetWord() << "  " << i->GetAmount() << endl;
    return os;
}

