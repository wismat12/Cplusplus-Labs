#ifndef PUNKT3D_H_INCLUDED
#define PUNKT3D_H_INCLUDED
#include "punkt.h"
using namespace std;

class Punkt3d: public Punkt
{
private:
    double z;
public:
    Punkt3d();
    Punkt3d(double _x, double _y, double _z);
    Punkt3d(const Punkt3d &punkt3d);
    ~Punkt3d();

    double distance(Punkt3d inny);

    //friend ostream & operator<<(ostream &,Punkt3d &);
};


#endif // PUNKT3D_H_INCLUDED
