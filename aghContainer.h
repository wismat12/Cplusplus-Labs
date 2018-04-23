/**
* \file aghContainer.h
* \author Mateusz Wisniewski
* \date 25.05.16
* \version 2.0
* \brief Plik naglowkowy zwierajacy interfejs kontenera
*/
/**
* === TDM-GCC Compiler Suite for Windows ===
* ---        GCC 4.7 & 4.8 Series        ---
* ***   Standard MinGW 32-bit Edition    ***
* ///  (Ubuntu 4.8.4-2ubuntu1~14.04.01)  ///
* ///         gcc version 4.8.4          ///
* valgrind --tool=memcheck --leak-check=full
*/
#ifndef AGHCONTAINER_H_INCLUDED
#define AGHCONTAINER_H_INCLUDED
// --------------------------------------------------------------
#include <iostream>
#include "aghException.h"
// --------------------------------------------------------------
using namespace std;
// --------------------------------------------------------------
template <typename U>
class aghVector;
template <typename U>
class aghDlist;
template <typename U>
class aghSlist;
// --------------------------------------------------------------
/**
* \class aghContainer
* \author Mateusz Wisniewski
* \date 25.05.16
* \brief Klasa abstrakcyjna reprezentujaca interfejs kontenera
*/
template <typename T>
class aghContainer
{
private:

public:

    /// \brief Virtualny destruktor
    /// <done>
    virtual ~aghContainer(){};

    /////////////////
    //METODY BAZOWE//
    /////////////////

    /// \brief Metoda dodawania elementu do pojemnika
    /// <done>
    /// \param dodaj�ca podany jako argument obiekt typu T do pojemnika
    void append(T const&);

    /// \brief podmienia obiekt typu T z obiektem na wybranym miejscu.
    /// <done>
    /// \return Zwraca true je�eli podane miejsce podmiany jest prawid�owe, w przeciwnym wypadku zwraca false.
    bool replace(int, T const&);

    /// \brief usuwa wszystkie elementy pojemnika
    /// <done>
    void clear(void);

    /// \brief Metoda sprawdzaj�ca czy pojemnik jest pusty:
    /// <done>
    /// \return zwraca true je�eli pojemnik jest pusty, inaczej false.
    bool isEmpty(void);

    /// \brief Metoda wyszukuj�ca element w pojemniku przez warto�� od zadanego momentu:
    /// <done>
    /// \return wyszukuje i zwraca indeks pierwszego elementu o warto�ci _value zaczynaj�c od elementu _from. Je�eli takiego elementu nie ma to zwraca -1.
    int indexOf(T const&, int) const;

    /// \brief  Metoda sprawdzaj�ca czy dany element jest ju� w pojemniku:
    /// <done>
    /// \return zwraca true je�eli element o warto�ci _value znajduje si� w pojemniku inaczej zwraca false. Wyszukiwanie rozpoczyna si� od elelmetnu _from.
    bool contains(T const&, int) const;

    /// \brief Metoda pomocnicza w przeszukiwaniu elementow w pojemniku przez warto�� od zadanego momentu:
    /// <done>
    /// \return wyszukuje i zwraca indeks pierwszego elementu o warto�ci _value zaczynaj�c od elementu _from. Je�eli takiego elementu nie ma to zwraca -1.
    int go_through_container(T const&, int) const;

    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

    /// \brief Przeciazony operator przypisania
    /// <done>
    aghContainer & operator=(aghContainer & aghCt) throw(aghException);

    /// \brief sprawdza czy zawarto�� pojemnik�w jest taka sama.
    /// <done>
    bool operator==(aghContainer<T> const& right);

    /// \brief sprawdza czy zawarto�� pojemnik�w jest r�na.
    /// <done>
    bool operator!=(aghContainer<T> const& right);

    /// \brief zwraca element o indeksie n.
    /// <done>
    T& operator[](int n) const throw(aghException);

    /// \brief dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
    /// <done>
    aghContainer<T>& operator+=(aghContainer<T> const& right);

    /// \brief dodaje element do pojemnika i zwraca referencje do this.
    /// <done>
    aghContainer<T>& operator+=(T const& element);

    /// \brief dodaje element do pojemnika i zwraca referencje do this.
    /// <done>
    aghContainer<T>& operator<<(T const& element);

    /// \brief dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
    /// <done>
    aghContainer<T>& operator<<(aghContainer<T> const& right);

    /// \brief wypisuje zawarto�� pojemnika na strumie�.
    /// <done>
    template <typename U> friend ostream& operator<<(ostream&, aghContainer<U> const&);

    /// \brief Metoda pomocnicza dodajaca element ze zwracaniem referencji
    /// <done>
    aghContainer<T>& addone(T const& element);

    /// \brief Metoda pomocnicza dodajaca wszystkie elementy ze zwracaniem referencji
    /// <done>
    aghContainer<T>& addall(aghContainer<T> const& right);

    /// \brief Metoda pomocnicza przy porownywaniu
    /// <done>
    bool is_the_same(aghContainer<T> const& right);

    ////////////////////////////////////////////////////////////////////////////////
    //METODY WIRTUALNE KTORYCH IMPLEMENTACJA ZOSTANIE ZAWARTA W KLASACH POCHODNYCH//
    ////////////////////////////////////////////////////////////////////////////////

    /// \brief wstawiaj�ca obiekt typu T w wybrane miejsce.
    /// <clean>
    /// \return Zwraca true je�eli podane miejsce wstawienia jest prawid�owe, w przeciwnym wypadku zwraca false.
    virtual bool insert(int, T const&) = 0;

    /// \brief Metoda zwracaj�ca warto�� elementu
    /// <clean>
    /// \return zwraca warto�� w pojemniku. Zak�adamy �e indeksowanie warto�ci rozpoczynamy od zera.
    virtual T& at(int) const = 0;

    /// \brief Metoda zwracaj�ca ilo�� element�w
    /// <clean>
    /// \return zwraca ilo�� element�w w pojemniku
    virtual int size(void) const = 0;

    /// \brief Metoda usuwaj�ca wybrany element:
    /// <clean>
    /// \return usuwa element na danym miejscu. Zwraca true je�eli podane miejsce usuni�cia jest prawid�owe, w przeciwnym wypadku zwraca false
    virtual bool remove(int) = 0;

    /// \brief Metoda niszczaca kontener
    /// <clean>
    virtual void kill_them_all(void) = 0;

    /// \brief Metoda Zwracajaca index ostatniego elementu
    /// <clean>
    virtual int last_index(void) const = 0;

    /// \brief Metoda Zwracajaca index ostatniego zaalokowanego elementu
    /// <clean>
    virtual int last_toal_index(void) const = 0;
};
// --------------------------------------------------------------
    /////////////////
    //METODY BAZOWE//
    /////////////////
// --------------------------------------------------------------
template <typename T>
void aghContainer<T>::append(T const &item)
{
    int last_item = this->last_index();
    this->insert(last_item + 1, item);
}
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::replace(int Chosen_position, T const &item)
{
    int Container_Length_Mem = this->last_total_index();

    if(Chosen_position <= Container_Length_Mem)
    {
        this->insert(Chosen_position, item);
        return true;

    }else
    {
        return false;
    }
}
// --------------------------------------------------------------
template <typename T>
void aghContainer<T>::clear(void)
{
    int Container_Length = this->last_index();

    for(int i = Container_Length; i >= 0; i--)
    {
        this->remove(i);
    }
}
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::isEmpty(void)
{
    int Container_Size = this->size();

    bool logic_value = (Container_Size == 0);

    return logic_value;
}
// --------------------------------------------------------------
template <typename T>
int aghContainer<T>::go_through_container(T const& _value, int _from = 0) const
{
    int Container_Length = this->last_index();

    for(int i = _from; i <= Container_Length; i++)
    {
        T tmp_value = this->at(i);

        if(tmp_value == _value)
        {
            return i;
        }
    }

    return -1;
}
// --------------------------------------------------------------
template <typename T>
int aghContainer<T>::indexOf(T const& _value, int _from = 0) const
{
    return this->go_through_container(_value, _from);
}
template <typename T>
bool aghContainer<T>::contains(T const& _value, int _from = 0) const
{
    int tell_me_sth = this->go_through_container(_value, _from);

    if(tell_me_sth >= 0)
    {
        return true;

    }else
    {
        return false;
    }
}
// --------------------------------------------------------------
    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::is_the_same(aghContainer<T> const& right)
{
    bool Sizes;
    bool Last_Positions;

    int Container_Size = this->size();
    int Container_Right_Size = right.size();
    int Last_Pos = this->last_index();
    int Last_Right_Pos = right.last_index();

    Sizes = (Container_Size == Container_Right_Size);
    Last_Positions = (Last_Pos == Last_Right_Pos);

    if(Sizes&&Last_Positions)
    {
        for(int i = 0; i < Container_Right_Size; i++)
        {
            if(this->at(i) != right.at(i))
            {
                return false;
            }
        }

    }else
    {
        return false;
    }

    return true;
}
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{
    return this->is_the_same(right);
}
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{
    return !(this->is_the_same(right));
}
// --------------------------------------------------------------
template <typename T>
T& aghContainer<T>::operator[](int n) const throw(aghException)
{
    int Container_length = this->last_index();

    if(Container_length < n) throw aghException(0, "Index out of range", __FILE__, __LINE__);

    return this->at(n);
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T> & aghContainer<T>::operator=(aghContainer<T> &aghCt) throw(aghException)
{
    if(this == &aghCt) return *this;

    /***************************************************/

    aghContainer<T> *base_ptr_this = this;

    aghContainer<T> *ptr_object = &aghCt;

    /***************************************************/

    aghVector<T> *derived_ptr_argVC = dynamic_cast< aghVector<T> *>(ptr_object); //rzutowanie w dol hierarchii

    if(derived_ptr_argVC == NULL)
    {
        aghDlist<T> *derived_ptr_argDL = dynamic_cast< aghDlist<T> *>(ptr_object);

        if(derived_ptr_argDL == NULL)
        {
            aghSlist<T> *derived_ptr_argSL = dynamic_cast< aghSlist<T> *>(ptr_object);

            if(derived_ptr_argSL == NULL)
            {
                 throw aghException(0, "Error with casting polymorph pointers - so sorry", __FILE__, __LINE__);
            }

            aghSlist<T> *derived_ptr_this = dynamic_cast< aghSlist<T> *>(base_ptr_this);

            if(derived_ptr_this == NULL)
            {
                throw aghException(0, "Error with comparing polymorph pointers - so sorry", __FILE__, __LINE__);
            }

            *derived_ptr_this = *derived_ptr_argSL;

            return *this;

        }

        aghDlist<T> *derived_ptr_this = dynamic_cast< aghDlist<T> *>(base_ptr_this);

        if(derived_ptr_this == NULL)
        {
            throw aghException(0, "Error with comparing polymorph pointers - so sorry", __FILE__, __LINE__);
        }

        *derived_ptr_this = *derived_ptr_argDL;

        return *this;

    }

    aghVector<T> *derived_ptr_this = dynamic_cast< aghVector<T> *>(base_ptr_this);

    if(derived_ptr_this == NULL)
    {
        throw aghException(0, "Error with comparing polymorph pointers - so sorry", __FILE__, __LINE__);
    }

    *derived_ptr_this = *derived_ptr_argVC;

    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::addone(T const& element)
{
    this->append(element);

    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::addall(aghContainer<T> const& right)
{
    int Container_Right_Size = right.last_index();

    for(int i = 0; i <= Container_Right_Size; i++)
    {
        this->append(right.at(i));
    }

    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right)
{
    return this->addall(right);
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element)
{
    return this->addone(element);
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element)
{
    return this->addone(element);
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right)
{
    return this->addall(right);
}
// --------------------------------------------------------------
template <typename T>
ostream& operator<<(ostream& os, aghContainer<T> const& right)
{

    int last_elem = right.last_index();

    if(last_elem < 0)
    {
        os << "EMPTY" << endl;
    }

    for(int i = 0; i <= last_elem; i++)
    {
        os << i + 1 << "." << right.at(i) << endl;
    }

    return os;
}
#endif // AGHCONTAINER_H_INCLUDED
