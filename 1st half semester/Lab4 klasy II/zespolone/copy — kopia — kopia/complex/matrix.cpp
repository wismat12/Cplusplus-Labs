#include "complex.h"
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <iomanip>
#include "matrix.h"
#include "WrongDimensionsException.h"

using namespace std;

struct Is_elem_num
{
    bool if_only_spaces;
    bool if_wrong_ascii;
};
bool validDimensions(*this, obj)
{
    if((this->rows == obj.rows)&&(this->cols == obj.cols))
        return true;
    else
        return true;
}
//Konstruktor bezparametrowy
Matrix::Matrix()
{
    rows = 3;
    cols = 3;
    allocate_mem();
    cout <<"Konstruktor Domyslny!!!" <<endl;
}
//Konstruktor parametrowy
Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    Complex init(0,0);
    allocate_mem();

    for(int i = 0;i < rows;i++)
        for(int j = 0;j < cols;j++)
            this->tab[i][j] = init;
    cout <<"Konstruktor Parametrowy!!!" <<endl;
}
//Konstruktor kopiujacy
Matrix::Matrix(const Matrix &_matrix)
{
    this->rows = _matrix.rows;
    this->cols = _matrix.cols;

    allocate_mem();

    for(int i = 0;i < this->rows;i++)
        for(int j = 0;j < this->cols;j++)
            this->tab[i][j] = _matrix.tab[i][j];

    cout <<"Konstruktor Kopiujacy!!!" <<endl;
}
//Konstruktor z notacja Matlaba
Matrix::Matrix(string text_matrix)
{
    read_string(text_matrix);
    cout <<"Konstruktor z notacja matlaba!!!" <<endl;
}
Matrix::~Matrix()
{
    if(tab != NULL)
    {
        for(int i = 0;i < rows;i++)
            delete[] tab[i];
        delete[] tab;
        cout <<"Destruktor!!!" <<endl;
    }
}

void Matrix::allocate_mem()
{
    this->tab = new Complex * [rows];
    // cout << "ALLOC"<<endl;
    for(int i = 0;i < rows;i++)
    {
        this->tab[i] = new Complex [cols];
        //cout << "ALLOC"<<endl;
    }

}

string Matrix::take_elements()
{
    string elements;
    cout << "Podaj liczbe zespolone w postaci ciagu [aib cid; eif gih], Program czyta nastepujace liczby bez wezgledu na ilosc spacji: "<< endl;
    cout << "0 0i i0 0i0 a srednik jest separatorem wierszy"<< endl;
    getline(cin, elements);
    return elements;
}

void Matrix::read_string(string elements)
{
    string rre, iim, te, re, im, line2,test,str, number;;

    unsigned int i, k, j, position, position2, cols_amount, rows_amount=1;

    vector <vector <string> > vc;
    Is_elem_num checked;

    bool asciierror = false;
    bool colserror = false;

    if(elements[0] == '[')  elements.erase(0,1);
    if(elements[elements.size()-1] == ']')   elements.erase(elements.end()-1,elements.end());

    for(i = 0; i < elements.size(); i++)
    {
        if(elements[i]==';')    rows_amount++;
    }

    while((position = elements.find(';')) != std::string::npos)
    {
        str = elements.substr(0, position);
        vector <string> n;
        n.push_back(str);
        vc.push_back(n);

        elements.erase(0, position + 1);
    }
    if(position==(std::string::npos))
    {
        vector <string> n;
        n.push_back(elements);
        vc.push_back(n);
    }

    for(k = 0;k < vc.size();k++)
    {
        do
        {
            position2 = vc[k][0].find(' ');

            number = vc[k][0].substr(0, position2);

            checked.if_only_spaces = true;
            checked.if_wrong_ascii = false;

            for(j = 0;j < number.size(); j++)
            {
                if((int)(number[j])!= 32)    checked.if_only_spaces = false;
                if(((int)(number[j]) < 48)&&((int)(number[j])!= 32)&&((int)(number[j])!= 46)&&((int)(number[j])!= 45))  //ascii 46 - kropka,ascci 45 -minus ascii 32 - spacja
                {
                    checked.if_wrong_ascii = true;
                    asciierror = true;
                }
            }
            if((checked.if_only_spaces==false)&&(checked.if_wrong_ascii==false))
                {
                    vc[k].push_back(number);
                    vc[k][0].erase(0, position2 + 1);

                }else
                {
                    vc[k][0].erase(0, position2 + 1);
                }

        }while(position2 != std::string::npos);
    }

    cols_amount = vc[0].size();
    cout << cols_amount << "  cols amount + 1" <<endl;

    for(unsigned int d = 0; d < vc.size(); d++)
    {
        for(unsigned int c = 1; c < vc[d].size(); c++)
        {
            cout << vc[d][c] << " sep ";
        }
        cout<<endl;
    }
    for(i = 1; i < vc.size(); i++)
    {
        cout << vc[i].size() << " temp cols amount +1" <<endl;
        if(cols_amount!=vc[i].size())
        {
            colserror = true;
            cout << "Blad! Niepoprawna ilosc kolumn" << endl;
            cout << rows << "  " << cols<<endl;
        }
    }
    if(!asciierror&&!colserror)
    {
        this->rows = rows_amount;
        this->cols = cols_amount-1;

        allocate_mem();
        cout << "Mem allocated\n";

    }else exit(-1);

    for(i = 0; i < vc.size(); i++)
    {
        for( j=1;j< vc[i].size();j++)
        {
            capture_numbers(vc[i][j],i,j-1);
        }

        cout << endl;
    }

}
void Matrix::capture_numbers(string num, int row, int col)
{
    string ree, iim;
    unsigned int ipos;

    ipos = num.find('i');
    ree = num.substr(0, ipos);
    iim = num.substr(ipos + 1, std::string::npos);

    Complex a;

    if(ipos==std::string::npos) tab[row][col].change(ree,"0");
    else
        if(ipos==0) tab[row][col].change("0",iim);
        else
            tab[row][col].change(ree,iim);
}
void Matrix::print()
{
    for(int i = 0;i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
            cout.width(18);

            cout << left << tab[i][j].print_onlynum();
        }
        cout << endl;
    }
}
Matrix Matrix::add(Matrix m) throw (WrongDimensionsException)
{
    //macierze takich samych rozmiarow
    if( !validDimensions(*this, obj) ) throw WrongDimensionsException(obj);

    Matrix tmp(rows, cols);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
            tmp.tab[i][j] = this->tab[i][j].addition(m.tab[i][j]);
        }
    }
    return tmp;
}
Matrix Matrix::sub(Matrix m)
{
    //macierze takich samych rozmiarow
    Matrix tmp(rows, cols);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
            tmp.tab[i][j] = this->tab[i][j].subtraction(m.tab[i][j]);
        }
    }
    return tmp;
}
Matrix Matrix::mul(Matrix m)
{
    //ilosc kolumn z pierwszej rowna ilosci wierszy z drugiej
    Matrix tmpmx(this->rows, m.cols);
    Complex tmp;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
            for(int c = 0;c < cols; c++)
            {
                tmp = tmp.addition(this->tab[i][c].multiplication(m.tab[c][j]));
            }
            tmpmx.tab[i][j] = tmp;
            tmp.setRe(0);
            tmp.setIm(0);
        }
    }

    return tmpmx;
}
Matrix Matrix::mul(Complex c)
{
    Matrix tmpmx(rows, cols);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
           tmpmx.tab[i][j] =  tab[i][j].multiplication(c);
        }
    }
    return tmpmx;
}
//Nie dziala Det LaPlace'em
Complex Matrix::detLaPlace(Matrix m)
{
    Complex n(-1,0);
    int x, y, a, b;

    if(m.cols==1) return m.tab[0][0];

        for(int j = 0;j < m.cols; j++)
        {
            cout <<"out:";
            out.print();
            cout <<endl;
                for( a =0; a < rows; a++)
                    for(b=0 ;b<cols;b++)
                    {
                        if(((tab[a][b].getRe())==(m.tab[0][j].getRe()))&&((tab[a][b].getIm())==(m.tab[0][j].getIm())))
                        {
                            x=a+1;
                            y=b+1;
                        }
                    }
            n.power( x+y).multiplication(m.tab[0][j]).print();
            cout <<endl;
            out = out.addition((n.power( x+y).multiplication(m.tab[0][j])).multiplication(detLaPlace(create_minor(j,0,m.cols-1))));
            cout <<"out:";
            out.print();
            cout <<endl;
        }
return out;
}
//Metoda odwracajaca macierz
Matrix Matrix::Inverse()
{
    Complex maindet = this->detLU();
   // maindet.print();
    if((maindet.getRe()!=0)||(maindet.getIm()!=0))
    {
        Complex tmpDet;
        Complex n(-1,0);

        Matrix cofactor_mx(rows,cols);

        for(int i = 0;i < rows;i++)
        {
            for(int j = 0;j < cols;j++)
            {
                //cofactor_mx.print();
                Matrix tmpMinorMX = this->create_minor(j, i, rows - 1);
                //tmpMinorMX.print();
                tmpDet = tmpMinorMX.detLU();

                tmpDet = n.power(i+1+j+1).multiplication(tmpDet);

                //tmpDet.print();

                cofactor_mx.tab[i][j] = tmpDet;
            }
        }
        //cofactor_mx.print();
        //cout << "TWychzodzi z petli!!!" << endl;

        Matrix cofactor_mxT_inv = cofactor_mx.transpose().mul(maindet.inv());

        //cout <<"wypisuje pzrmnozona m\n";
        //cofactor_mxT_inv.print();
        //cout <<"JUZ\n";
        return cofactor_mxT_inv;
    }else
    {
        cout << "Det = 0!!!\n";
        return Matrix(rows,cols);
    }
}
//Transponowanie macierzy
Matrix Matrix::transpose()
{
    Matrix transposed(rows,cols);

    for(int i = 0;i < rows;i++)
    {
        for(int j = 0;j < cols;j++)
        {
            transposed.tab[i][j] = tab[j][i];
        }
    }
    return transposed;
}
//Liczenie wyznacznika metoda LU
Complex Matrix::detLU()
{
    int k = 0;
    int i, j, n;
    Matrix m = *this;

    if(m.rows > 1){
    do
    {
        m.normLU(k,k);

        for(i = 1 +k;i < m.rows;i++)
            for(j = 1 +k; j < m.cols; j++)
                m.tab[i][j] = m.tab[i][j].subtraction(m.tab[i][k].multiplication(m.tab[k][j]));
        k++;
    }while(k < m.cols -1 );

    Complex out = m.tab[0][0];

    for(n = 1; n < m.cols;n++)
        out = out.multiplication(m.tab[n][n]);

    return out;
    }else return m.tab[0][0];
}
//Normalizacja elementow kolumny przez zadany element
void Matrix::normLU(int startrow, int startcol)
{
    for(int i = startrow + 1;i < this->rows;i++)
    {
        this->tab[i][startcol] = this->tab[i][startcol].division(this->tab[startrow][startcol]);
    }
}
//Tworzenie macierzy do obliczenia minora
Matrix Matrix::create_minor(int col_to_del, int row_to_del, int deg)
{
    Matrix tmp(deg,deg);
    int column = 0;
    int row = 0;
    for(int i = 0;i < this->rows; i++)
    {
        for(int j = 0;j < this->cols;j++)
        {
            if((i!=row_to_del)&&(j!=col_to_del))
            {
               tmp.tab[row][column] = this->tab[i][j];
               column++;
            }
        }
        if(i!=row_to_del)   row++;
        column = 0;
    }
    return tmp;
}
//Dzielenie macierzy na rzecz ktorej wywolywana jest metoda i m jako parametr
//Przemnozenie macierzy przez odrotna z parametru
Matrix Matrix::div(Matrix m)
{
    return  this->mul(m.Inverse());
}
//Dzielenie macierzy na rzecz ktorej wywolywana jest metoda i liczby c jako parametr
Matrix Matrix::div(Complex c)
{
    return  this->mul(c.inv());
}

Matrix Matrix::pow(int exponent)
{
    if(this->rows == this->cols)  //Czy jest kwadratowa??
    {
        if(exponent == 1)    return *this;
        if(exponent == -1)   return this->Inverse();
        if(exponent != 0)
        {
            Matrix m = this->mul(*this);

            if(exponent == 2)   return m;
            if(exponent ==-2)   return m.Inverse();
            if(exponent < 0)
            {
                while(exponent < -2)
                {
                    exponent++;
                    Matrix::RewriteMemory( m, m.mul(*this));
                }
                return m.Inverse();
            }
            if(exponent > 0)
            {
                while(exponent > 2)
                {
                    exponent--;
                    Matrix::RewriteMemory( m, m.mul(*this));
                }
                return m;
            }
        }else
        {
            //Macierz jednostkowa
            Complex one(1,0);
            Matrix IdentityMx(this->rows,this->cols);
            for(int i = 0; i < this->rows; i++)
                IdentityMx.tab[i][i] = one;
            return IdentityMx;
        }
    }else
        cout << "Potegowanie niemozliwe" << endl;
}
//Matrix Input zostaje zamieniony na output
void Matrix::RewriteMemory(Matrix &input, Matrix output)
{
    if(input.tab != NULL)
    {
        for(int i = 0;i < input.rows;i++)
            delete[] input.tab[i];
        delete[] input.tab;
    }
    input.rows = output.rows;
    input.cols = output.cols;
    input.allocate_mem();
    for(int i = 0;i < input.rows;i++)
        for(int j = 0;j < input.cols;j++)
            input.tab[i][j] = output.tab[i][j];
}



