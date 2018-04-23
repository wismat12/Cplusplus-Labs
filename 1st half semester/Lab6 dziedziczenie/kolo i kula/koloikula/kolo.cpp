#include "kolo.h"
#include <math.h>
#include <iostream>
#define PI 3.14159265359
using namespace std;
Kolo::Kolo():x(0),y(0),r(0)
{
    cout << "Konstruktor bezparametrowy z klasy Kolo" << endl;
}

Kolo::Kolo(double _x, double _y, double _r)
{
    cout << "Konstruktor parametrowy z klasy Kolo" << endl;
    x = _x;
    y = _y;
    r = _r;
}

Kolo::Kolo(const Kolo &kolo)
{
    cout << "Konstruktor kopiujacy z klasy Kolo!" << endl;
    this->x = kolo.x;
    this->y = kolo.y;
    this->r = kolo.r;
}

Kolo::~Kolo(){
    cout << "Destruktor z klasy Kolo" << endl;
}

double Kolo::pole()
{
    cout << "Pole z klasy Kolo" << endl;
    return PI * r * r;
}
