#include<iostream>
#include"para.h"
#include<string>
Para::Para(string s)
{
    word = s;
    amount = 1;
}
Para::Para(const Para & p)
{
    this->word = p.word;
    this->amount = p.amount;
}

//Op prefiksowy ++c  c.operator++();
Para & Para::operator++()
{
    ++(this->amount);
    return *this;
}
//Op postfiksowy dla c++  c.operator++(int 0);
Para Para::operator++(int i)
{
    Para tmp = *this;
    ++(this->amount);
    return tmp;
}

bool Para::operator>(const Para & p)
{
    cout << "Sprawdzasz czy liczba wystapien slowa " << this->word << " > " << p.word;
    if(this->amount > p.amount) return true;
    else
        return false;
}
bool Para::operator==(const Para & p)
{
    cout << "Sprawdzasz czy liczba wystapien slowa " << this->word << " == " << p.word;
    if(this->amount == p.amount) return true;
    else
        return false;
}
bool Para::operator<(const Para & p)
{
    cout << "Sprawdzasz czy liczba wystapien slowa " << this->word << " < " << p.word;
    if(this->amount < p.amount) return true;
    else
        return false;
}
Para & Para::operator=(const Para & p)
{
    this->word = p.word;
    this->amount = p.amount;
    return *this;
}
