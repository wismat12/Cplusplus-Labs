#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include "complex.h"

using namespace std;
class Matrix
{
private:
    Complex **tab;
    int rows;
    int cols;
    string w;
public:
    //Konstruktor bezparametrowy
    Matrix();
    //KOnsutruktor parametrowy
    Matrix(int rows, int cols);
    //Konstruktor kopiujacy
    Matrix(const Matrix &_matrix);
    //Konstruktor z notacja Matlaba
    Matrix(string text_matrix);
    ~Matrix();

    void allocate_mem();
    Complex out;
    static string take_elements();
    void read_string(string elements);
    void capture_numbers(string num, int row, int col);

    void SetNumber(int row_to_set, int col_to_set);
    void GetNumber(int row_to_Get, int col_to_Get);

    //
    Complex test(Matrix m, int i, int j);
    Complex detLU(Matrix m);
    void normLU(Matrix &m, int startrow, int startcol);
    Matrix transpose(Matrix m);
    Matrix Inverse(Matrix m);
    Matrix create_minor(Matrix x,int col_to_del, int row_to_del, int deg);
    Complex detLaPlace(Matrix m);

    //Operacje
    Matrix add(Matrix m);
    Matrix sub(Matrix m);
    Matrix mul(Matrix m);
    Matrix mul(Complex c);


    void print();
};


#endif // MATRIX_H_INCLUDED
