#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
//#include "complex.h"

using namespace std;

class Complex;

class WrongDimensionsException;
class WrongDimensions_MUL_Exception;
class DivisionByZeroException;
class NotSquareMatrixException;
class WrongStringException;

class Matrix
{
private:
    Complex **tab;
    int rows;
    int cols;
public:
    //Konstruktor bezparametrowy
    Matrix();
    //Konstruktor parametrowy
    Matrix(int rows, int cols);
    //Konstruktor kopiujacy
    Matrix(const Matrix &_matrix);
    //Konstruktor z notacja Matlaba
    Matrix(string text_matrix);
    //Destruktor
    ~Matrix();

    void RewriteMemory(Matrix &input, Matrix output);
    void allocate_mem();
    static string take_elements();
    void read_string(string elements) throw (WrongStringException);
    void capture_numbers(string num, int row, int col);

    void SetNumber(int row_to_set, int col_to_set, Complex);
    //void GetNumber(int row_to_Get, int col_to_Get);
    int GetRowsAmount(){return this->rows;}
    int GetColsAmount(){return this->cols;}
    Complex out;

    //Metody do odwrocenia macierzy
    Complex detLU() throw (NotSquareMatrixException);
    Matrix transpose();
    Matrix Inverse() throw (DivisionByZeroException, NotSquareMatrixException);
    void normLU(int startrow, int startcol) throw (DivisionByZeroException);
    Matrix create_minor(int col_to_del, int row_to_del, int deg);

    //Operacje na macierzach
    Matrix add(Matrix &m) throw (WrongDimensionsException);
    Matrix sub(Matrix &m) throw (WrongDimensionsException);
    Matrix mul(Matrix m) throw (WrongDimensions_MUL_Exception);
    Matrix mul(Complex c);
    Matrix div(Matrix m);
    Matrix div(Complex c) throw (DivisionByZeroException);
    Matrix pow(int exponent) throw (NotSquareMatrixException);

    void print();
    friend ostream & operator<<(ostream & os, const Matrix & m);


};


#endif // MATRIX_H_INCLUDED
