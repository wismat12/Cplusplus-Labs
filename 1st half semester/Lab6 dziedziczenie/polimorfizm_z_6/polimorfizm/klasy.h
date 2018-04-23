#ifndef KLASY_H_INCLUDED
#define KLASY_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Umowa
{
protected:
    double wynagrodzenieBrutto;
    string typ;
public:
    Umowa(double pensja , string _typ):wynagrodzenieBrutto(pensja), typ(_typ){};
    virtual double pobierzNetto() = 0;
    double pobierzBrutto(){return wynagrodzenieBrutto;};
    string sprawdztyp(){return typ;};
};


class UmowaDzielo: public Umowa{
public:
    UmowaDzielo(double pensja):Umowa(pensja," UmowaDzielo "){};
    virtual double pobierzNetto(){return 0.80*wynagrodzenieBrutto;};
};


class UmowaPraca: public Umowa{
public:
    UmowaPraca(double pensja):Umowa(pensja," UmowaPraca "){};
    virtual double pobierzNetto(){return 0.76*wynagrodzenieBrutto;};
};


class Pracownik
{
private:
    string imie,nazwisko,pesel;
    Umowa *umowa;
public:
    Pracownik(string i,string n,string p,Umowa *u): imie(i),nazwisko(n),pesel(p),umowa(u){};
    Pracownik(const Pracownik& p)
    {
        this->imie = p.imie;
        this->nazwisko = p.nazwisko;
        this->pesel = p.pesel;
        this->umowa = p.umowa;
    };
    ~Pracownik(){};
    double pobierzPensjeBrutto(){return umowa->pobierzBrutto();};

    friend ostream& operator<<(ostream & os,Pracownik & p)
    {        os << p.imie << " " << p.nazwisko << " Pesel: " << p.pesel << p.umowa->sprawdztyp() << " PensjaNetto: " << p.umowa->pobierzNetto() << " PensjaBrutto " << p.pobierzPensjeBrutto() << endl;

        return os;
    };

};




#endif // KLASY_H_INCLUDED
