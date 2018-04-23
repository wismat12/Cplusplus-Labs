#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include "complex.h"
#include "matrix.h"
#include "MultipleExceptions.h"
using namespace std;

int main(int argc, char* argv[])
{
    /*stringstream strt1;
    stringstream strt2;
    strt1 << argv[1];
    strt2 << argv[2];
    string t1 = strt1.str();
    string t2 = strt2.str();*/

    Matrix m1;
    Matrix m2;
  //  Matrix tmp1;
   //- Matrix tmp2;
    try
    {
        Matrix tmp1("1 2 ;3 4");
        Matrix tmp2("3 3 5 ;3 3 3");
        m1.RewriteMemory(m1, tmp1);
        m2.RewriteMemory(m2, tmp2);
    }catch(WrongStringException wr){
        wr.printMessage();
        return(-1);
    }


    cout << "Macierz pierwsza: ";
    m1.print();
    cout << "Macierz druga: ";
    m2.print();

    try
    {
        //cout << "Dodawanie ";
        //(m1.add(m2)).print();

       // cout << "Odejmowanie ";
       // (m1.sub(m2)).print();

      //  cout << "Mno¿enie ";
       // (m1.mul(m2)).print();

     //   cout << "Dzielenie";
      //  (m1.div(m2)).print();

        cout << "Potegowanie ";
        (m1.pow(2)).print();

        cout << "Potegowanie ";
        (m2.pow(2)).print();


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
    cout << "------------------------------------"<< endl;


    return 0;
}
