#include "complex.h"
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <iomanip>

#include "matrix.h"
using namespace std;

struct Is_elem_num
{
    bool if_only_spaces;
    bool if_wrong_ascii;
};
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
    for(int i = 0;i < rows;i++)
        for(int j = 0;j < cols;j++)
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
    for(int i = 0;i < rows;i++)
        delete[] tab[i];
    delete[] tab;
    cout <<"Destruktor!!!" <<endl;

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

        do{
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
            cout.width(15);

            cout << left << tab[i][j].print_onlynum();
           // tab[i][j].print();
            //cout.fill('_');
            //cout << tab[i][j].Re; << " ";
           /* cout.flags(std::ios_base::left);
            cout.width(3);

            cout << left << tab[i][j].print_onlynum();*/
        }
        cout << endl;
    }
}
Matrix Matrix::add(Matrix m)
{
    //macierze takich samych rozmiarow
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
    Matrix tmpmx(rows, m.cols);
    Complex tmp;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
            for(int c = 0;c < cols; c++)
            {
                tmp.addition(tab[i][j + c].multiplication(m.tab[i + c][j]));
            }
            tmpmx.tab[i][j] = tmp;
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
            out = out.addition((n.power( x+y).multiplication(m.tab[0][j])).multiplication(detLaPlace(create_minor(m,j,0,m.cols-1))));
            cout <<"out:";
            out.print();
            cout <<endl;
        }
return out;
}
Matrix Matrix::Inverse(Matrix m)
{
    Complex maindet = m.detLU(m);
   // maindet.print();
    Complex tmpDet;
    Complex n(-1,0);


    Matrix cofactor_mx(m.rows,m.rows);
    for(int i = 0;i < m.rows;i++)
    {
        for(int j = 0;j < m.cols;j++)
        {
            tmpDet = n.power(i+1+j+1).multiplication(m.create_minor( m, j, i, m.rows - 1).detLU(m.create_minor( m, j, i, m.rows - 1)));
            Matrix tmpMinor = m.create_minor( m, j, i, m.rows - 1);

            tmpMinor.print();

            tmpDet = tmpMinor.detLU(tmpMinor);
                        //tmpDet.print();
            tmpDet = n.power(i+1+j+1).multiplication(tmpDet);
            tmpDet.print();


            cofactor_mx.tab[i][j] = tmpDet;
            tmpMinor.~Matrix();
        }
    }





    cofactor_mx = cofactor_mx.transpose(cofactor_mx);

    cofactor_mx = cofactor_mx.mul(maindet);
     cout << "TEST!!!" << endl;

    return cofactor_mx;
}
Complex Matrix::test(Matrix m, int i, int j)
{




//    return tmpDet;

}
Matrix Matrix::transpose(Matrix m)
{
    Matrix transposed(m.rows,m.rows);

    for(int i = 0;i < m.rows;i++)
    {
        for(int j = 0;j < m.cols;j++)
        {
            transposed.tab[i][j] = m.tab[j][i];
        }
    }
    return transposed;
}
Complex Matrix::detLU(Matrix m)
{
    int k = 0;
    int i, j, n;

    if(m.rows > 1){
    do
    {
        m.normLU(m,k,k);

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

void Matrix::normLU(Matrix &m, int startrow, int startcol)
{
    for(int i = startrow + 1;i < m.rows;i++)
    {
        m.tab[i][startcol] = m.tab[i][startcol].division(m.tab[startrow][startcol]);
    }
}

Matrix Matrix::create_minor(Matrix x, int col_to_del, int row_to_del, int deg)
{
    Matrix tmp(deg,deg);
    int column = 0;
    int row = 0;
    for(int i = 0;i < x.rows; i++)
    {
        for(int j = 0;j < x.cols;j++)
        {
            if((i!=row_to_del)&&(j!=col_to_del))
            {
               tmp.tab[row][column] = x.tab[i][j];
               column++;
            }

        }
        if(i!=row_to_del)   row++;
        column = 0;
    }
    return tmp;
}



