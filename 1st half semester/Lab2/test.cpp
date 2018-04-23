#include <iostream>
using namespace std;

int * potega(int liczba, int potega){
  int *wynik = &liczba;
  //cout << *wynik;
  for(int i = 1; i < potega; i++){
    (*wynik) *= liczba;
    cout << *wynik<<"  "<<liczba<<endl;}
  return wynik;
}
int main(void){
    int n;
    n = *(potega(3,3));
  cout << n << endl;
}
