#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

class Complex{
  private:
    double Re;
    double Im;
    double Mod;
    double Arg;
  public:
    //Konstruktor bezparametrowy
    Complex();
    //Konstruktor parametrowy
    Complex(double _Re, double _Im);
    //Konstruktor kopiujacy
    Complex(const Complex &_complex);
    //Destruktor
    ~Complex();

    void setmod();
    void setarg();
    void add();

    Complex addition(Complex item1);
    Complex subtraction(Complex item1);
    Complex multiplication(Complex item1);
    Complex division(Complex item1);
    Complex power(double exponent);

    double getRe(){return Re;}
    double getIm(){return Im;}
    void setRe(double _Re){Re=_Re;}
    void setIm(double _Im){Im=_Im;}

    void print();
};


#endif // COMPLEX_H_INCLUDED
