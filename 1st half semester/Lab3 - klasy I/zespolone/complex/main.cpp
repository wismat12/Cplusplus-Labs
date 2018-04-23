#include <iostream>
#include "complex.h"
#include <cmath>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;


    Complex a(2,2);
    Complex b(3,4);
    Complex c(-2,-1);

    Complex t1, t2, t3, t4, t5;

    a.print();
    b.print();
    c.print();

    cout << "Dodawanie: ";
    t1 = a.addition(b);
    t1.print();
    cout << endl;

    cout << "Odejmowanie: ";
    t2 = a.subtraction(b);
    t2.print();
    cout << endl;

    cout << "Mnozenie: ";
    t3 = a.multiplication(b);
    t3.print();
    cout << endl;

    cout << "Dzielenie: ";
    t4 = a.division(c);
    t4.print();
    cout << endl;

    cout << "Potegowanie: ";
    t5 = b.power(6);
    t5.print();
    cout << endl;

    return 0;
}
