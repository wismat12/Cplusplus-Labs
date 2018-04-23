#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "punkt.h"

class Square{
  private:
    Punkt a,b,c,d;
  public:
    //Konstruktor bezparametrowy
    Square();
    //Konstruktor parametrowy
    Square(Punkt  _a, Punkt _b, Punkt _c, Punkt _d);
    //Destruktor
    ~Square();

    void obwod();
    void pole();
};


#endif // SQUARE_H_INCLUDED
