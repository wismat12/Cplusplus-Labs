#include "dtab.h"
#include <iostream>

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
        cout << "\nRealokacja " << endl;

        bufor = new double [newSize];
        for(int i = 0;i < last; i++)
            bufor[i] = tab[i];

        delete[] tab;

        tab = new double [newSize];


        tab = bufor;



        length = newSize;
    }
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
    {
        cout << "Blad indexu!" << endl;
        return -1;
    }
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
    cout.precision(3);
    for(int i = 0; i < last; i++)
    {
        cout << "(index " << i << ") " << tab[i] << endl;
    }

}



