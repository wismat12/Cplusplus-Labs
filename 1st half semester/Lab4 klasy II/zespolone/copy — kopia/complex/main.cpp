#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include "complex.h"
#include "matrix.h"
#include "MultipleExceptions.h"
using namespace std;
//Jesli bledy to zamienic npos'a na -1 w matrix.cpp
int main(int argc, char* argv[])
{

/*  Przyklad rzutowania obiektu Complex na typ matrix
    Complex c("5","3");
    Matrix nowa = (Matrix)c;
    cout << nowa;
*/
    //GLOWNY PROGRAM
    stringstream strt1;
    stringstream strt2;
    strt1 << argv[1];
    strt2 << argv[2];
    string t1 = strt1.str();
    string t2 = strt2.str();

    Matrix m1;
    Matrix m2;
    Matrix tmp1;
    Matrix tmp2;
    try
    {
        Matrix tmp1(t1);
        Matrix tmp2(t2);
        m1.RewriteMemory(m1, tmp1);
        m2.RewriteMemory(m2, tmp2);
    }catch(WrongStringException wr){
        wr.printMessage();
        return(-1);
    }

    cout << "Macierz pierwsza: " << m1;
    cout << "Macierz druga: " << m2;

    try
    {
        cout << "Dodawanie " << m1.add(m2);
        cout << "Odejmowanie " << m1.sub(m2);
        cout << "Mnozenie " << m1.mul(m2);
        cout << "Dzielenie" << m1.div(m2);
        cout << "Potegowanie pierwszej" << m1.pow(2);
        cout << "Potegowanie drugiej" << m2.pow(2);

    }catch(WrongDimensionsException w)
    {
        w.printMessage();
        return(-1);
    }catch(WrongDimensions_MUL_Exception mul)
    {
        mul.printMessage();
        return(-1);
    }catch(DivisionByZeroException zero)
    {
        zero.printMessage();
        return(-1);
    }catch(NotSquareMatrixException square)
    {
        square.printMessage();
        return(-1);
    }

    return 0;
}
