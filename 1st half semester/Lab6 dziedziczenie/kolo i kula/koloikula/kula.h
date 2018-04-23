#ifndef KULA_H_INCLUDED
#define KULA_H_INCLUDED
#include "kolo.h"

using namespace std;

class Kula: public Kolo
{
private:
    double z;
public:
    Kula();
    Kula(double _x, double  _y, double  _z, double  _r);
    Kula(const Kula &);
    ~Kula();
    double pole();
};




#endif // KULA_H_INCLUDED
