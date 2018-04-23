#ifndef MULTIPLEEXCEPTIONS_H_INCLUDED
#define MULTIPLEEXCEPTIONS_H_INCLUDED
#include <iostream>
using namespace std;

class Matrix;

class WrongDimensionsException
{
private:
    Matrix obj1, obj2;
    const char *info;

public:
    WrongDimensionsException(Matrix _obj1, Matrix _obj2, const char *text):obj1(_obj1),obj2(_obj2),info(text){}
    void printMessage();
};
inline void WrongDimensionsException::printMessage()
{
    cout << "Blad w " << info << " > ";
    cout << "Zobacz ze pierwsza macierz" << endl;
    obj1.print();
    cout << "Ma wymiary " << obj1.GetRowsAmount() << " X " << obj1.GetColsAmount() << " Z kolei druga macierz" << endl;
    obj2.print();
    cout << "Ma wymiary " << obj2.GetRowsAmount() << " X " << obj2.GetColsAmount() << " Co uniemozliwia przeprowadzenie dzialania"  << endl;
}
class WrongDimensions_MUL_Exception
{
private:
    Matrix obj1, obj2;

public:
    WrongDimensions_MUL_Exception(Matrix _obj1, Matrix _obj2):obj1(_obj1),obj2(_obj2){}
    void printMessage();
};
inline void WrongDimensions_MUL_Exception::printMessage()
{
    cout << "Zobacz ze pierwsza macierz" << endl;
    obj1.print();
    cout << "Ma wymiary " << obj1.GetRowsAmount() << " X " << obj1.GetColsAmount() << " Z kolei druga macierz" << endl;
    obj2.print();
    cout << "Ma wymiary " << obj2.GetRowsAmount() << " X " << obj2.GetColsAmount() << endl;
    cout << obj1.GetColsAmount() << " != " <<  obj2.GetRowsAmount() << " Wiec mnozenie nie moze zostac przeprowadzone!" << endl;
}
class DivisionByZeroException
{
private:
    Matrix obj1;
    const char *info;

public:
    DivisionByZeroException(Matrix _obj1, const char *text):obj1(_obj1),info(text){}
    void printMessage();
};
inline void DivisionByZeroException::printMessage()
{
    cout << "Blad >" << info << " > ";
    cout << "Spojrz na macierz" << endl;
    obj1.print();
    cout << "Dzialania poprowadza do sytuacji dzielenia przez zero!" << endl;

}
class NotSquareMatrixException
{
private:
    Matrix obj1;
    const char *info;

public:
    NotSquareMatrixException(Matrix _obj1, const char *text):obj1(_obj1),info(text){}
    void printMessage();
};
inline void NotSquareMatrixException::printMessage()
{
    cout << "Blad >" << info << " > ";
    cout << "Liczba wierszy nie rowna sie liczbie kolumn (nie jest kwadratowa): " << obj1.GetRowsAmount() << " != " << obj1.GetColsAmount() << endl;
    cout << "Spojrz na macierz i ocen" << endl;
    obj1.print();
}
class WrongStringException
{
private:
    const char *info;

public:
    WrongStringException(const char *text):info(text){}
    void printMessage();
};
inline void WrongStringException::printMessage()
{
    cout << "Blad >" << info << "\n > dzialanie programu zostanie przerwane";
}


#endif // MULTIPLEEXCEPTIONS_H_INCLUDED
