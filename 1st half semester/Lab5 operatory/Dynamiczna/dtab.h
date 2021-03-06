#ifndef DTAB_H_INCLUDED
#define DTAB_H_INCLUDED
#include <iomanip>
using namespace std;
class DTab{
  private:
    double * tab;
    int length;
    int last;

    // Metoda rozszerzajaca rozmiar tablicy do rozmiaru podanego jako parametr
    void resize(int newSize);
  public:
    // Konstruktor bezparametrowy. Powinien tworzy� tablic� o rozmiarze 10. (wykorzystaj metode resize)
    DTab();
    // Tworzy tablice o rozmiarze podanym jako parametr. (wykorzystaj metode resize)
    DTab(int initLength);
    //Kopiujacy
    DTab(const DTab &);
    // Destruktor. Uwaga! Tablic� tworzymy dynamicznie, czyli tutaj jest wymagany!
    ~DTab();

    // Dodaje element do na koniec tablicy. Je�li tablica jest za ma�a
    // rozszerza j�. (wykorzystaj metode resize)
    void add(double element);
    // Pobiera element z tablicy z podanego indexu
    double get(int index);
    // Ustawia element o danym indeksie na dan� warto��
    void set(double element, int index);
    // wy�wietla tablice.
    void print();
    double & operator[](int index);
    DTab & operator=(DTab &);

    DTab & operator++();
    DTab operator++(int);

    friend ostream & operator<<(ostream &, const DTab &);

};



#endif // DTAB_H_INCLUDED
