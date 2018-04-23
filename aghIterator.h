/**
* \file aghIterator.h
* \author Mateusz Wisniewski
* \date 05.06.16
* \version 1.0
* \brief Plik naglowkowy reprezentujacy szablon ITERATORA
*/
// --------------------------------------------------------------
/**
* === TDM-GCC Compiler Suite for Windows ===
* ---        GCC 4.7 & 4.8 Series        ---
* ***   Standard MinGW 32-bit Edition    ***
* ///  (Ubuntu 4.8.4-2ubuntu1~14.04.01)  ///
* ///         gcc version 4.8.4          ///
* valgrind --tool=memcheck --leak-check=full
*/
#ifndef AGHITERATOR_H_INCLUDED
#define AGHITERATOR_H_INCLUDED

#include "aghContainer.h"
#include "aghException.h"

template <typename T>
class aghIterator
{
private:
    aghContainer<T> *type;  ///< Typ kontenera dla ktorego iterator zostal przyporzadkowany
    int position;           ///< Pozycja wskazywana przez iterator
public:

    /// \brief Konstruktor domyslny
    ///
    aghIterator(): type(NULL), position(0){};

    /// \brief Konstruktor kopiujacy
    ///
    aghIterator(aghContainer<T> *arg_obj);

    /// \brief Konstruktor kopiujacy
    ///
    aghIterator(aghIterator<T> &arg_obj);

    /// \brief Destruktor
    ///
    ~aghIterator(){};

    /// \brief zwraca iterator pokazuj¹cy na pierwszy element w pojemniku
    ///
    aghIterator first();

    /// \brief zwraca iterator pokazuj¹cy na ostatni element w pojemniku
    ///
    aghIterator last();

    /// \brief przesuwa iterator na nastêpny element
    ///
    aghIterator<T>& next();

    /// \brief przesuwa iterator na poprzedni element
    ///
    aghIterator<T>& prev();

    /// \brief zwraca aktualnie pokazywany element w pojemniku, oraz umo¿liwia zmianê wartoœci tego elementu
    ///
    T& current() throw(aghException);

    /// \brief przenosi iterator na pierwszy element w pojemniku
    ///
    aghIterator<T>& atFirst();

    /// \brief przenosi iterator na ostatni element w pojemniku
    ///
    aghIterator<T>& atLast();

    /// \brief zwraca iloœæ elementów od aktualnie pokazywanego do ostatniego elementu w pojemniku
    ///
    int size();

    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

    /// \brief zwraca element znajduj¹cy siê o i pozycji dalej wzglêdem aktualnego elementu.
    ///
    T& operator[](int);

    /// \brief sprawdzenie czy iterator pokazuje na pojemnik, ewentualnie czy pojemnik zawiera przynajmniej jeden element oraz czy aktualnie pokazywany element jest poprawny.
    ///
    operator int() const;

    /// \brief zwraca aktualnie pokazywany element
    ///
    T& operator*();

    /// \brief zwraca iterator przesuniêty o i elementów dalej.
    ///
    aghIterator operator+(int);

    /// \brief zwraca iterator przesuniêty o i elementów bli¿ej.
    ///
    aghIterator operator-(int);

    /// \brief przesuwa iterator o i elementów dalej.
    ///
    void operator+=(int);

    /// \brief przesuwa iterator o i elementów wczeœniej.
    ///
    void operator-=(int);

    /// \brief przesuwa iterator na i+1 element i zwraca iterator pokazuj¹cy na i+1 element.
    ///
    aghIterator & operator++(); //Op prefiksowy ++c c.operator++()

    /// \brief zwraca iterator pokazuj¹cy na i-ty element a nastêpnie przesuwa iterator na i+1 element.
    ///
    aghIterator operator++(int); //Op postfiksowy dla c++  c.operator++(0)

    /// \brief przesuwa iterator na i-1 element i zwraca iterator pokazuj¹cy na i-1 element.
    ///
    aghIterator & operator--();

    /// \brief zwraca iterator pokazuj¹cy na i-ty element a nastêpnie przesuwa iterator na i-1 element.
    ///
    aghIterator operator--(int);

    /// \brief porównanie dwóch iteratorów - s¹ sobie równe tylko wtedy gdy pokazuj¹ na ten sam element.
    ///
    bool operator==(aghIterator<T> & aghIT);

    /// \brief porównanie dwóch iteratorów - s¹ rozne wtedy gdy nie pokazuj¹ na ten sam element.
    ///
    bool operator!=(aghIterator<T> & aghIT);

    /// \brief Przypisuje iterator z argumentu do obiektu na ktorym zostal wywolany
    ///
    aghIterator & operator=(const aghIterator<T> & aghIT);

    /// \brief ustawia pojemnik na który iterator pokazuje
    ///
    void operator=(const aghContainer<T> & aghCt);
};
// --------------------------------------------------------------
template <typename T>
aghIterator<T>::aghIterator(aghContainer<T> *arg_obj)
{
    this->type = arg_obj;
    this->position = 0;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T>::aghIterator(aghIterator<T> &arg_obj)
{
    this->type = arg_obj.type;
    this->position = arg_obj.position;
}
// --------------------------------------------------------------
template <typename T>
T& aghIterator<T>::current() throw(aghException)
{
    if((position < 0) || (position > type->last_index()))
    {
        throw aghException(0, "Iterator refers to undefined element", __FILE__, __LINE__);
    }
    return type->at(position);
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T>& aghIterator<T>::next()
{
    ++this->position;
    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T>& aghIterator<T>::prev()
{
    --this->position;
    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T> aghIterator<T>::first()
{
    aghIterator<T> new_iter(*this);
    new_iter.position = 0;
    return new_iter;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T> aghIterator<T>::last()
{
    aghIterator<T> new_iter(*this);
    new_iter.position = this->type->last_index();
    return new_iter;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T>& aghIterator<T>::atFirst()
{
    this->position = 0;
    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T>& aghIterator<T>::atLast()
{
    this->position = this->type->last_index();
    return *this;
}
// --------------------------------------------------------------
template <typename T>
int aghIterator<T>::size()
{
    return this->type->last_index() - this->position + 1;
}
// --------------------------------------------------------------
template <typename T>
T& aghIterator<T>::operator[](int index)
{
    return this->type->at(this->position + index);
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T>::operator int() const
{
    if((position < 0) || (position > type->last_index()) || (this->type == NULL))
    {
        return NULL;

    }else
    {
        return this->type->at(this->position);
    }
}
// --------------------------------------------------------------
template <typename T>
T& aghIterator<T>::operator*()
{
    return this->type->at(this->position);
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T> aghIterator<T>::operator+(int step)
{
    aghIterator<T> new_iter(*this);
    new_iter.position = this->position + step;
    return new_iter;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T> aghIterator<T>::operator-(int step)
{
    aghIterator<T> new_iter(*this);
    new_iter.position = this->position - step;
    return new_iter;
}
// --------------------------------------------------------------
template <typename T>
void aghIterator<T>::operator+=(int step)
{
    this->position += step;
}
// --------------------------------------------------------------
template <typename T>
void aghIterator<T>::operator-=(int step)
{
    *this += -step;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T> & aghIterator<T>::operator++()
{
    this->position++;
    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T> aghIterator<T>::operator++(int i)
{
    aghIterator<T> tmp(*this);
    this->position++;
    return tmp;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T> & aghIterator<T>::operator--()
{
    this->position--;
    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T> aghIterator<T>::operator--(int i)
{
    aghIterator<T> tmp(*this);
    this->position--;
    return tmp;
}
// --------------------------------------------------------------
template <typename T>
bool aghIterator<T>::operator==(aghIterator<T> & aghIT)
{
    if((this->type->at(this->position)) == (aghIT.type->at(aghIT.position)))
    {
        return true;
    }
    return false;
}
// --------------------------------------------------------------
template <typename T>
bool aghIterator<T>::operator!=(aghIterator<T> & aghIT)
{
    if(*this == aghIT)
    {
        return false;
    }
    return true;
}
// --------------------------------------------------------------
template <typename T>
aghIterator<T>& aghIterator<T>::operator=(const aghIterator<T> & aghIT)
{
    if(this == &aghIT) return *this;

    this->type = aghIT.type;
    this->position = aghIT.position;

    return *this;
}
// --------------------------------------------------------------
template <typename T>
void aghIterator<T>::operator=(const aghContainer<T> & aghCt)
{
    this->type = aghCt.type;
    this->position = 0;

    return *this;
}
// --------------------------------------------------------------
#endif // AGHITERATOR_H_INCLUDED
