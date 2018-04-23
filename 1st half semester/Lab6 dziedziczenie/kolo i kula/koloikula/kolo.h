#ifndef KOLO_H_INCLUDED
#define KOLO_H_INCLUDED
using namespace std;

class Kolo
{
private:
    double x, y, r;
public:
    Kolo();
    Kolo(double _x, double _y, double _r);
    Kolo(const Kolo &);
    ~Kolo();
    double pole();

    double GetR(){return r;};
};


#endif // KOLO_H_INCLUDED
