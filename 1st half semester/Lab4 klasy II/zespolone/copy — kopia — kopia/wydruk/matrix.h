#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include "WrongDimensionsException.h"
#include "complex.h"

using namespace std;
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
    void read_string(string elements);
    void capture_numbers(string num, int row, int col);

    void SetNumber(int row_to_set, int col_to_set);
    void GetNumber(int row_to_Get, int col_to_Get);
    Complex out;

    //Metody do odwrocenia macierzy
    Complex detLU();
    Matrix transpose();
    Matrix Inverse();
    void normLU(int startrow, int startcol);
    Matrix create_minor(int col_to_del, int row_to_del, int deg);
    Complex detLaPlace(Matrix m);

    //Operacje na macierzach
    Matrix add(Matrix m) throw (WrongDimensionsException);
    Matrix sub(Matrix m);
    Matrix mul(Matrix m);
    Matrix mul(Complex c);
    Matrix div(Matrix m);
    Matrix div(Complex c);
    Matrix pow(int exponent);

    void print();
};
#endif // MATRIX_H_INCLUDED
