#include "kula.h"
#include "kolo.h"
#include <math.h>
#include <iostream>
#define PI 3.14159265359
using namespace std;
Kula::Kula() : Kolo(),z(0)
{
    cout << "Konstruktor bezparametrowy z klasy Kula" << endl;
}

Kula::Kula(double _x, double _y, double _z, double _r) : Kolo(_x,_y,_r)
{
    cout << "Konstruktor parametrowy z klasy Kula" << endl;
    z = _z;
}

Kula::Kula(const Kula &kula) : Kolo(kula)
{
    cout << "Konstruktor kopiujacy z klasy Kula!" << endl;
    this->z = kula.z;
}

Kula::~Kula()
{
    cout << "Destruktor z klasy Kula" << endl;
}

double Kula::pole()
{
    cout << "Pole z klasy Kula" << endl;
    return 4 * PI * pow(this->GetR(),2);
}
