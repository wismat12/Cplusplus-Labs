#ifndef WRONGDIMENSIONSEXCEPTION_H_INCLUDED
#define WRONGDIMENSIONSEXCEPTION_H_INCLUDED
#include <iostream>

#include "complex.h"
#include "matrix.h"
using namespace std;



class WrongDimensionsException
{
private:
    Matrix obj;
public:
    WrongDimensionsException(Matrix _obj):obj(_obj){}

    void printMessage(){
        cout << "Wymiary macierzy " << endl;
        obj.print();
        cout << "Sa niepoprawne!" << endl;
    }
};





#endif // WRONGDIMENSIONSEXCEPTION_H_INCLUDED
