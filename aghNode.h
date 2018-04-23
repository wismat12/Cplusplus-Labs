/**
* \file aghNode.h
* \author Mateusz Wisniewski
* \date 05.06.16
* \version 1.0
* \brief Plik naglowkowy przchowujacy struktury Wezlow
*/
#ifndef AGHNODE_H_INCLUDED
#define AGHNODE_H_INCLUDED
/**
* \class nodeSL
* \author Mateusz Wisniewski
* \date 25.05.16
* \brief Struktura dla wezla listy jednokierunkowej
*/
template <typename T>
class nodeSL
{
public:
    T item;
    nodeSL<T> *next;
};
/**
* \class nodeDL
* \author Mateusz Wisniewski
* \date 25.05.16
* \brief Struktura dla wezla listy dwukierunkowej
*/
template <typename T>
class nodeDL
{
public:
    T item;
    nodeDL<T> *next;
    nodeDL<T> *prev;

};
/**
* \class element
* \author Mateusz Wisniewski
* \date 08.05.16
* \brief Struktura dla elementu umieszczanego w Vectorze
*/
template <typename T>
struct element
{
    T item;
    bool exist;

};
#endif // AGHNODE_H_INCLUDED
