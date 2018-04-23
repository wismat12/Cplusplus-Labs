#ifndef PUNKT_H_INCLUDED
#define PUNKT_H_INCLUDED
#include <iomanip>
using namespace std;
//class Punkt3d;
class Punkt{
    //friend class Punkt3d;
  private:
    double x, y;
  public:
    //Konstruktor bezparametrowy
    Punkt();
    //Konstruktor parametrowy
    Punkt(double _x, double _y);
    //Konstruktor kopiujacy
    Punkt(const Punkt &punkt);
    //Destruktor
    ~Punkt();

    double distance(Punkt inny);
    void wyswietl();

    // Krótkie funkcje mog¹ byæ zdefiniowane w pliku
    // nag³ówkowym i bêd¹ traktowane jako funkcje inline
    double getX(){return x;}
    double getY(){return y;}
    void setX(double _x){x=_x;}
    void setY(double _y){y=_y;}

    istream & operator>>(istream &);
    friend istream & operator>>(istream &, Punkt &);
    friend ostream & operator<<(ostream &, const Punkt &);
};

#endif // PUNKT_H_INCLUDED
