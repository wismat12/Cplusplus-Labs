#include <iostream>
#include "punkt.h"
#include "square.h"
using namespace std;

int main(void){
  Punkt p;
  Punkt p2(12,34);
  Punkt p3 = p2;
  Punkt p4(p3);

  Punkt *ptrP = new Punkt(3,4);

  p2.wyswietl();
  cout <<  ptrP->distance(p2) << endl;  //Kopiujacy


  /*  Square A;

    A.obwod();
    A.pole();*/

  delete ptrP;

}
