/**
* \file aghSlist.h
* \author Mateusz Wisniewski
* \date 25.05.16
* \version 1.0
* \brief Plik naglowkowy reprezentujacy szablon LISTY JEDNOKIERUNKOWEJ
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
#ifndef AGHSLIST_H_INCLUDED
#define AGHSLIST_H_INCLUDED
// --------------------------------------------------------------
#include "aghContainer.h"
#include "aghException.h"
#include "aghNode.h"
// --------------------------------------------------------------
/**
* \class aghSlist
* \author Mateusz Wisniewski
* \date 25.05.16
* \brief Implementacja Kontenera typu LISTA JEDNOKIERUNKOWA
*/
template <typename T>
class aghSlist: public aghContainer<T>
{
private:

    nodeSL<T> *head;   		///< Wskaznik na poczatek listy
    int Size;               ///< ilosc wezlow w liscie

public:

    /// \brief Konstruktor domyslny
    /// <done>
    aghSlist();

    /// \brief Konstruktor kopiujacy
    /// <done>
    aghSlist(aghContainer<T> &arg_obj);

    /// \brief Destruktor dla listy jednokierunkowej
    /// <done>
    virtual ~aghSlist();

    /////////////////////
    //METODY POMOCNICZE//
    /////////////////////

    /// \brief Metoda pomocnicza zwalniajaca pamiec
    /// <done>
    void free_memory(void);

    /// \brief Metoda pomocnicza usuwajaca node'a
    /// <done>
    void delete_node(int);

    //////////////////////////////////
    //METODY WIRTUALNE DLA AGHVECTOR//
    //////////////////////////////////

    /// \brief wstawiaj¹ca obiekt typu T w wybrane miejsce.
    /// <done>
    /// \return Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
    virtual bool insert(int, T const&);

    /// \brief Metoda zwracaj¹ca wartoæ elementu
    /// <done>
    /// \return zwraca wartoæ w pojemniku. Zak³adamy ¿e indeksowanie wartoci rozpoczynamy od zera.
    virtual T& at(int) const throw(aghException);

    /// \brief Metoda zwracaj¹ca iloæ elementów
    /// <done>
    /// \return zwraca iloæ elementów w pojemniku
    virtual int size(void) const;

    /// \brief Metoda usuwaj¹ca wybrany element:
    /// <done>
    /// \return usuwa element na danym miejscu. Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false
    virtual bool remove(int);

    /// \brief Metoda niszczaca kontener
    /// <done>
    virtual void kill_them_all(void);

    /// \brief Metoda Zwracajaca index ostatniego elementu
    /// <done>
    virtual int last_index(void) const;

    /// \brief Metoda Zwracajaca index ostatniego zaalkowanego elementu
    /// <done>
    virtual int last_toal_index(void) const;

    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

    /// \brief Przeciazony operator przypisania w przypadku gdy dostaniemy wskaznik bazowy
    /// <done>
    aghSlist & operator=(const aghContainer<T> & obj);

    /// \brief Przeciazony operator przypisania w przypadku gdy dostaniemy wskaznik pochodny
    /// <done>
    aghSlist & operator=(const aghSlist<T> & aghDl);

};

// --------------------------------------------------------------
template <typename T>
aghSlist<T>::aghSlist()
{
    this->Size = 0;
    this->head = NULL;
}
// --------------------------------------------------------------
template <typename T>
aghSlist<T>::aghSlist(aghContainer<T> &arg_obj)
{
    aghContainer<T> *base_ptr = &arg_obj;

    aghSlist<T> *derived_ptr = dynamic_cast< aghSlist<T> *>(base_ptr);

    this->head = NULL;

    nodeSL<T> *iterator_tmp;

    iterator_tmp = derived_ptr->head;

    for(int i = 0; i < derived_ptr->Size; i++)
    {
        this->insert(i, iterator_tmp->item);

        iterator_tmp = iterator_tmp->next;
    }
}
// --------------------------------------------------------------
template <typename T>
aghSlist<T>::~aghSlist()
{
    this->free_memory();
}
// --------------------------------------------------------------
    /////////////////////
    //METODY POMOCNICZE//
    /////////////////////
// --------------------------------------------------------------
template <typename T>
void aghSlist<T>::free_memory(void)
{

    if(this->Size != 0)
    {
        while(this->Size != 0)
        {
            this->delete_node(0);

        }

        this->head = NULL;
    }
}
// --------------------------------------------------------------
template <typename T>
void aghSlist<T>::delete_node(int position)
{
    if(position == 0)
    {                                           //< Usuwanie head'a
        nodeSL<T> *tmp;

        tmp = this->head;

        this->head = this->head->next;

        delete tmp;

        this->Size--;

    }else
    if(position == this->Size - 1)
    {                                           //< Usuwanie taile'a
        nodeSL<T> *iterator_tmp;
        nodeSL<T> *iterator_tmp_do_delete;

        iterator_tmp = this->head;

        for(int i = 0; i < position - 1; i++)
        {
            iterator_tmp = iterator_tmp->next;
        }
        iterator_tmp_do_delete = iterator_tmp->next;

        iterator_tmp->next = NULL;

        delete iterator_tmp_do_delete;

        this->Size--;

    }else
    {
                                                //< usuwanie innych
        nodeSL<T> *iterator_tmp;
        nodeSL<T> *iterator_tmp_do_delete;

        iterator_tmp = this->head;

        for(int i = 0; i < position - 1; i++)
        {
            iterator_tmp = iterator_tmp->next;
        }

        iterator_tmp_do_delete = iterator_tmp->next;

        iterator_tmp->next = iterator_tmp_do_delete->next;

        delete iterator_tmp_do_delete;

        this->Size--;
    }
}
// --------------------------------------------------------------
template <typename T>
int aghSlist<T>::last_toal_index(void) const
{
    return this->Size;
}
// --------------------------------------------------------------
    ///////////////////////////////
    //DEFINICJE METOD WIRTUALNYCH//
    ///////////////////////////////
// --------------------------------------------------------------
template <typename T>
bool aghSlist<T>::insert(int position, T const& item)
{
    if(this->Size < position)
    {
        return false;

    }else
    {
        if(this->head == NULL)
        {                                          //< PUSTA LISTA
            nodeSL<T> *new_node = new nodeSL<T>;

            new_node->item = item;

            new_node->next = NULL;

            this->head = new_node;

            this->Size++;

            return true;
        }

        if(position == this->Size)
        {                                           //< Dodawanie na koncu
            nodeSL<T> *new_node = new nodeSL<T>;

            new_node->item = item;
            new_node->next = NULL;

            nodeSL<T> *iterator_tmp;

            iterator_tmp = this->head;

            for(int i = 0; i < position - 1; i++)
            {
                iterator_tmp = iterator_tmp->next;
            }

            iterator_tmp->next = new_node;

            this->Size++;

            return true;
        }

        if(position == 0)
        {                                           //< Dodawanie na poczatku
            nodeSL<T> *new_node = new nodeSL<T>;

            new_node->item = item;

            new_node->next = this->head;

            this->head = new_node;

            this->Size++;

            return true;
        }
                                                    //< Dodawanie w srodku
        nodeSL<T> *new_node = new nodeSL<T>;

        nodeSL<T> *iterator_tmp;

        iterator_tmp = this->head;

        for(int i = 0; i < position - 1; i++)
        {
            iterator_tmp = iterator_tmp->next;
        }

        new_node->next = iterator_tmp->next;
        iterator_tmp->next = new_node;

        this->Size++;

        return true;
    }
}
// --------------------------------------------------------------
template <typename T>
T& aghSlist<T>::at(int position) const throw(aghException)
{
    if((position >= this->Size)||(position < 0))
    {
        throw aghException(0, "Index refers to undefined element", __FILE__, __LINE__);

    }else
    {

        nodeSL<T> *iterator_tmp;

        iterator_tmp = this->head;

        for(int i = 0; i < position; i++)
        {
            iterator_tmp = iterator_tmp->next;
        }

        return iterator_tmp->item;
    }
}
// --------------------------------------------------------------
template <typename T>
int aghSlist<T>::size(void) const
{
    return this->Size;
}
template <typename T>
int aghSlist<T>::last_index(void) const
{
    return this->Size - 1;
}
// --------------------------------------------------------------
template <typename T>
bool aghSlist<T>::remove(int position)
{
    if(position >= this->Size) return false; //czy chcemy usunac poza zakresem

    this->delete_node(position);

    return true;
}
// --------------------------------------------------------------
template <typename T>
void aghSlist<T>::kill_them_all(void)
{
    //cout <<"THIS IS SPARTA!!!!!" << endl;
    this->free_memory();
}
// --------------------------------------------------------------
    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////
// --------------------------------------------------------------
template <typename T>
aghSlist<T>& aghSlist<T>::operator=(const aghContainer<T> & obj)
{
    aghContainer<T>& base_ptr = const_cast<aghContainer<T>&>(obj);

    aghSlist<T> *aghDl = dynamic_cast< aghSlist<T> *>(&base_ptr);

    if(this == aghDl) return *this;

    this->free_memory();

    nodeSL<T> *iterator_tmp;

    iterator_tmp = aghDl->head;

    for(int i = 0; i < aghDl->Size; i++)
    {
        this->insert(i, iterator_tmp->item);

        iterator_tmp = iterator_tmp->next;
    }

    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghSlist<T>& aghSlist<T>::operator=(const aghSlist<T> & aghDl)
{
    if(this == &aghDl) return *this;

    this->free_memory();

    nodeSL<T> *iterator_tmp;

    iterator_tmp = aghDl.head;

    for(int i = 0; i < aghDl.Size; i++)
    {
        this->insert(i, iterator_tmp->item);

        iterator_tmp = iterator_tmp->next;
    }

    return *this;
}
#endif // AGHSLIST_H_INCLUDED
