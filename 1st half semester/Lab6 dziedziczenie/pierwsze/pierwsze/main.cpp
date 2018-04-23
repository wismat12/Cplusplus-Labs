#include <iostream>
using namespace std;

class LiczbaRzeczywista{
  protected:
    double re;
  public:
    LiczbaRzeczywista(double r){re=r;}
    void wypisz(){
      cout << re;
      cout << "-Metoda z klasy Re" << endl;
    }
    void powitaj(){

      cout << "Czesc!";
      cout << "-Metoda z klasy Re" << endl;
    }

    LiczbaRzeczywista operator+(const LiczbaRzeczywista& r){
      cout << "-Metoda z klasy Re - przeladowany +" << endl;
      LiczbaRzeczywista rr(re+r.re);
      return rr;
    }

};

class LiczbaZespolona : public LiczbaRzeczywista{
  protected:
    double im;
  public:
    LiczbaZespolona(double re, double i):LiczbaRzeczywista(re){im=i;}
    void wypisz(){

      cout << re << " + " << im << "i";
      cout << "-Metoda z klasy ReIm" << endl;
    }
};

int main(){
  LiczbaRzeczywista a(12);
  LiczbaZespolona b(23,5);

  a.powitaj();         //Czesc!
  a.wypisz();          //12
  (a+a).wypisz();      //24

  b.powitaj();         //Czesc!
  b.wypisz();          //23 + 5I


  (b+b).wypisz();      //Co siê wypisze?
}
