#include <iostream>
#include <math.h>
#include "punkt.h"
#include "punkt3d.h"
using namespace std;

Punkt3d::Punkt3d() : Punkt(), z(0)
{
    cout << "Konstruktor bezparametrowy z klasy Punkt3d" << endl;
}

Punkt3d::Punkt3d(double _x, double _y, double _z) : Punkt(_x,_y)
{
    cout << "Konstruktor parametrowy z klasy Punkt3d" << endl;
    z = _z;
}

Punkt3d::Punkt3d(const Punkt3d &punkt3d) : Punkt(punkt3d)
{
    cout << "Konstruktor kopiujacy z klasy Punkt3d!" << endl;
    this->z = punkt3d.z;
}

Punkt3d::~Punkt3d()
{
    cout << "Destruktor z klasy Punkt3d" << endl;
}

double Punkt3d::distance(Punkt3d inny)
{
    return sqrt(pow(this->getX()-inny.getX(),2)+pow(this->getY()-inny.getY(),2)+pow(z-inny.z,2));
}

/*ostream & operator<<(ostream & os,  Punkt3d & p)
{
    os << "(" << p.getX() << ";" << p.getY() << ";" << p.z << ")";
    return os;
}*/
