#include <iostream>
#include "complex.h"
#include "matrix.h"
#include "WrongDimensionsException.h"
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    //  Matrix g("2 9;8 11");
    // Matrix g("1i3 2i-4 3i3 8;3 2i12 1i-9 9;2i12 1 3 11i-111;12 54i1 12 587i-90");
    //Macierz testowa 5x5
    // Matrix g("      13412.243    313.13    4432.00001   5132.13  6132.132 ;  631.14  813.1423   343.23552434   113.142   632.3465    ; 3134.2354i123.142      43215.1345342i123.142     -7689.4532i-6325.14422     5244.1234   3433.14;123542.4523 53426.132 72436.123 3322.45 113.123;-3454.54i87.14 43.43 123.123i89.34 1323.132 978.423       ");
    Matrix a("1 2;3 5");
    Matrix b("2 3;4 5");
    try{
        cout << a.add(b) << endl;

    }catch(WrongDimensionsException w){


    }


    //Matrix wynik = a.pow(50);
    Matrix wynik = a.div(b);
    wynik.print();




    cout << "------------------------------------"<< endl;


    return 0;
}
