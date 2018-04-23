#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "complex.h"
#include "MultipleExceptions.h"

#define PI 3.14159265359
using namespace std;
bool EqualZero(Complex item)
{
    if((item.getRe() == 0)&&(item.getIm() == 0)) retrun true;
    else
        return false;
}
Complex::Complex()
{
   // cout << "Konstruktor domyslny!\n";
    Re = 0;
    Im = 0;
    Arg = 0;
    Mod = 0;
}
Complex::Complex(double _Re, double _Im)
{
  //  cout << "Konstruktor parametrowy(double)!\n";
    Re = _Re;
    Im = _Im;
    setmod();
    setarg();
}
Complex::Complex(string rre, string iim)
{
   // cout << "Konstruktor parametrowy(string)!\n";
    stringstream(rre)>>Re;
    stringstream(iim)>>Im;
    setmod();
    setarg();
}
Complex::Complex(const Complex & _complex)
{
   // cout << "Konstruktor kopiujacy!\n";
    this->Re = _complex.Re;
    this->Im = _complex.Im;
    this->Mod =_complex.Mod;
    this->Arg =_complex.Arg;
  //  cout << "Konstruktor kopiujacy!\n";
}
Complex::~Complex()
{
    //cout << "Destruktor!\n";
}

void Complex::change(string rre, string iim)
{
    string re, im, line, line2;

    //cout << "Podaj liczbe zespolone w postaci aib, np.: 5i3" << endl;

    //getline(cin, re, 'i');
    //getline(cin, im);

    stringstream(rre)>>this->Re;
    stringstream(iim)>>this->Im;
    setmod();
    setarg();

}
void Complex::setmod()
{
    Mod = sqrt(pow(Re,2) + pow(Im,2));
}
void Complex::setarg()
{
    if(Re == 0)
    {
        if(Re == 0) Arg = 0;
        else
        {
            if(Im > 0) Arg = PI/2;
            else
            {
                Arg = (3/2)*PI;
            }
        }
    }
    else
    {
        if(Im == 0)
        {
            if(Re > 0) Arg = 0;
            else
            {
                Arg = PI;
            }
        }
        else
        {
            if(Re > 0)
            {
                if(Im > 0) Arg = asin(Im/Mod);
                else
                {
                    Arg = (3/2)*PI + asin(Im/Mod);
                }
            }
            else
            {
                if(Im > 0)
                {
                    Arg = PI/2 + asin(Im/Mod);
                }
                else
                {
                    Arg = PI + asin(Im/Mod);
                }
            }
        }
    }
}
Complex Complex::addition(Complex item1)
{
    double _Re, _Im;
    _Re = Re + item1.Re;
    _Im = Im + item1.Im;
    Complex tmp(_Re, _Im);
    return tmp;

}
Complex Complex::subtraction(Complex item1)
{
    double _Re, _Im;
    _Re = Re - item1.Re;
    _Im = Im - item1.Im;
    Complex tmp(_Re, _Im);
    return tmp;
}
Complex Complex::multiplication(Complex item1)
{
    double _Re, _Im;
    _Re = Re * item1.Re - (Im * item1.Im);
    _Im = Re * item1.Im + Im * item1.Re;
    Complex tmp(_Re, _Im);
    return tmp;
}
Complex Complex::division(Complex item1) throw (ComplexDivisonByZeroExp)
{
    if(EqualZero(item1)) throw ComplexDivisonByZeroExp();
    double _Re, _Im;
    item1.setIm(-1 * item1.Im);
    double div = pow(item1.Re, 2) + pow(item1.Im, 2);

    _Re = (Re * item1.Re - (Im * item1.Im))/div;
    _Im = (Re * item1.Im + Im * item1.Re)/div;

    Complex tmp(_Re, _Im);
    return tmp;
}
Complex Complex::power(double exponent)
{
    double _Re, _Im;
    _Re = pow(Mod, exponent) * cos(exponent*Arg);
    _Im = pow(Mod, exponent) * sin(exponent*Arg);
    Complex tmp(_Re, _Im);
    return tmp;
}
Complex Complex::inv() throe (ComplexDivisonByZeroExp)
{
    if(EqualZero(*this)) throw ComplexDivisonByZeroExp();
    Complex one(1,0);
    Complex tmp = one.division(*this);
    return tmp;

}
void Complex::print()
{
    cout.precision(4);
    cout << Re << "i" << Im;// << "i || Argument: " << Arg << "==Pi*" << Arg/PI << endl;
}
string Complex::print_onlynum()
{
    stringstream iim;
    stringstream ree;

    double dtmpIm = Im * 10000.0;
    int itmpIm = (int)(dtmpIm);
    dtmpIm =(double)(itmpIm)/10000.0;

    double dtmpRe = Re * 10000.0;
    int itmpRe = (int)(dtmpRe);
    dtmpRe =(double)(itmpRe)/10000.0;

    // sprintf(r,"%.2f",Re);#include <cstdio>
    ree << setprecision(2) << dtmpRe;
    iim << setprecision(2) << dtmpIm;

    string strr = ree.str() + "i" + iim.str();
    return strr;
}
