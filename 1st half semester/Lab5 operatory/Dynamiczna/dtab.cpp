#include "dtab.h"
#include <iostream>
#include <iomanip>
using namespace std;

void DTab::resize(int newSize)
{
    double * bufor;
    if(length == 0)
    {
        cout << "Alokacja poczatkowa" << endl;
        tab = new double [newSize];
        length = newSize;
    }
    else
    {
        cout << "Realokacja " << endl;

        bufor = new double [newSize];
        for(int i = 0;i < last; i++)
            bufor[i] = tab[i];

        delete[] tab;

        tab = new double [newSize];


        tab = bufor;



        length = newSize;
    }
}
DTab::DTab(const DTab & t)
{
    this->length = t.length;
    this->last = t.last;
    this->resize(t.length);
    for(int i = 0;i < t.length;i++)
        this->tab[i] = t.tab[i];
}

DTab::DTab()
{
    cout << "Utworzona domyslnie" << endl;
    length = 0;
    last = 0;
    resize(10);

}

DTab::DTab(int initLength)
{
    cout << "Utworzona z parametrem " << endl;
    length = 0;
    last = 0;
    resize(initLength);
}

DTab::~DTab()
{
    cout << "Destrukcja!!" << endl;
    delete[] tab;
}

void DTab::add(double element)
{
    if(last < length)
    {

        tab[last] = element;
        cout << "dodano!";
        last++;
    }
    else
    {

        resize((int)(1.5 * length));
        tab[last] = element;
        cout << "dodano!";
        last++;
    }
}

double DTab::get(int index)
{
    if(index < length)
        for(int i = 0; i < length; i++)
        {
            if(i == index)  return tab[i];
        }
    else

        cout << "Blad indexu!" << endl;
        return -1;

}

void DTab::set(double element, int index)
{
    if(index < length)
        for(int i = 0; i < length; i++)
        {
            if(i == index)  tab[i] = element;
        }
    else
    {
        cout << "Blad indexu!" << endl;
    }
}

void DTab::print()
{
    cout << "DTab length: " << length << endl;
    cout.precision(3);
    for(int i = 0; i < last; i++)
    {
        cout << "(index " << i << ") " << tab[i] << endl;
    }

}
double & DTab::operator[](int index)
{
    return this->tab[index];
}
DTab & DTab::operator=(DTab & d)
{
    delete[] this->tab;
    this->tab = new double [d.length];
    this->length = d.length;
    this->last = d.last;
    for(int i = 0;i < d.length;i++)
        this->tab[i] = d.tab[i];
    return *this;
}
//Op prefiksowy ++c
DTab & DTab::operator++()
{
    cout <<"PRe";
    this->resize(this->length + 1);
    return *this;
}
//Op postfiksowy dla c++  c.operator++(0)
DTab DTab::operator++(int i)
{
    cout <<"POst";
    DTab tmp = *this;
    this->resize(this->length + 1);
    return tmp;
}
ostream & operator<<(ostream & os, const DTab & d)
{
    os << "DTab length: " << d.length << endl;
    os.precision(3);
    for(int i = 0; i < d.last; i++)
    {
        os << "(index " << i << ") " << d.tab[i] << endl;
    }
    return os;

}



