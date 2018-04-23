//Definicja znajduje siê w pliku punkt.cpp
#include "punkt.h"
#include <math.h>
#include <iostream>

using namespace std;

/* Aby wskazaæ, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasiêgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne s¹ inicjowane
//nim zostanie wywo³ane cia³o konstruktora
Punkt::Punkt():x(0),y(0){
  cout << "Konstruktor bezparametrowy" << endl;
}

Punkt::Punkt(double _x, double _y){
  cout << "Konstruktor parametrowy" << endl;
  x = _x;
  y = _y;
}

Punkt::Punkt(const Punkt &punkt){
this->x = punkt.x;
this->y = punkt.y;
cout << "Konstruktor kopiujący!" << endl;
}

Punkt::~Punkt(){
  cout << "Destruktor! Nic nie robie, bo nie musze zwalniaæ pamiêci!";
  cout << endl;
}
istream & Punkt::operator>>(istream & input)
{
   input.ignore();    // Ignoruj nawias
   input >> this->x;
   input.ignore();    // Ignoruj przecinek
   input >> this->y;
   input.ignore();    // Ignowruj nawias
   return input;      // Umożliwia cin >> a >> b >> c;
}

istream & operator>>(istream & input, Punkt & p)
{
   input.ignore();    // Ignoruj nawias
   input >> p.x;
   input.ignore();    // Ignoruj przecinek
   input >> p.y;
   input.ignore();    // Ignowruj nawias
   return input;      // Umożliwia cin >> a >> b >> c;
}
ostream & operator<<(ostream & os, const Punkt & p)
{
    os << "(" << p.x << ";" << p.y << ")";
    return os;
}

double Punkt::distance(Punkt inny){
  return sqrt(pow(x-inny.x,2)+pow(y-inny.y,2));
}

void Punkt::wyswietl(){
  cout << "(" << x << ";" << y << ")";
}


