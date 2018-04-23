#include <math.h>
#include <iostream>
#include "square.h"
#include "punkt.h"
using namespace std;

Square::Square(){
  cout << "Konstruktor bezparametrowy" << endl;
  a.setX(0); a.setY(5);
  b.setX(5); b.setY(5);
  c.setX(5); c.setY(0);
  d.setX(0); d.setY(0);
}

Square::Square(Punkt _a, Punkt _b, Punkt _c, Punkt _d){
  cout << "Konstruktor parametrowy" << endl;
  a.setX(_a.getX());
  a.setY(_a.getY());
  b.setX(_b.getX());
  b.setY(_b.getY());
  c.setX(_c.getX());
  c.setY(_c.getY());
  d.setX(_d.getX());
  d.setY(_d.getY());
}

Square::~Square(){
  cout << "Destruktor! Nic nie robie, bo nie musze zwalniaæ pamiêci!";
  cout << endl;
}

void Square::obwod(){

  double krawedz;

  krawedz = a.distance(b);

  cout << "Obwod jest rowny " << 4*krawedz << endl;
}

void Square::pole(){

  double krawedz;

  krawedz = a.distance(b);

  cout << "Pole jest rowne " << pow(krawedz,2) << endl;
}
