#include <iostream>
#include "complex.h"
#include "matrix.h"
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
  //  Matrix g("2 9;8 11");
    Matrix g("1 2 3; 4 5 6;7 8 9");//
   //Matrix g("1 -1 2;3 0 -4;2 3 5");

   Matrix h = g.Inverse(g);
   h.print();
   /*Complex n(-1,0);
   Complex d = g.detLU(g);
    Complex t;
    t = n.power(2).multiplication(g.detLU(g.create_minor(g,0,0,2)));
    t.print();*/


   cout << "------------------------------------"<< endl;
  // Matrix tt = g.create_minor(g,0,2);
   //tt.print();

    //g.read_string(Matrix::take_elements());
   // j.print();






    return 0;
}
