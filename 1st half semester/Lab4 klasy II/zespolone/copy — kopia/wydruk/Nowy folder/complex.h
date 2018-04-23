#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <string>
using namespace std;

class ComplexDivisonByZeroExp;
class Complex
{
  private:
    double Re;
    double Im;
    double Mod;
    double Arg;
  public:
    //Konstruktor bezparametrowy
    Complex();
    //Konstruktory parametrowe
    Complex(double _Re, double _Im);
    //
    Complex(string rre, string iim);
    //Konstruktor kopiujacy
    Complex(const Complex &_complex);
    //Destruktor
    ~Complex();

    void setmod();
    void setarg();
    void change(string rre, string iim);

    Complex addition(Complex item1);
    Complex subtraction(Complex item1);
    Complex multiplication(Complex item1);
    Complex division(Complex item1); //throw (ComplexDivisonByZeroExp);
    Complex power(double exponent);
    Complex inv();// throw (ComplexDivisonByZeroExp);

    double getRe(){return Re;}
    double getIm(){return Im;}
    void setRe(double _Re){Re=_Re;}
    void setIm(double _Im){Im=_Im;}

    void print();
    string print_onlynum();
};


#endif // COMPLEX_H_INCLUDED
