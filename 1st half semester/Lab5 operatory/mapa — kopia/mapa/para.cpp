#include<iostream>
#include"para.h"
#include<string>
Para::Para(string s)
{
    word = s;
    amount = 1;
}

void Para::inc()
{
    amount++;
}
void Para::print()
{
    cout << word << endl << amount << endl;
}
void Para::operator++()
{

    this->amount = this->amount + 1;

}
bool Para::operator>(const Para & p)
{
    if(this->amount > p.amount) return true;
    else
        return false;
}
bool Para::operator==(const Para & p)
{
    if(this->amount == p.amount) return true;
    else
        return false;
}
bool Para::operator<(const Para & p)
{
    if(this->amount < p.amount) return true;
    else
        return false;
}
void Para::operator=(const Para & p)
{
    this->word = p.word;
    this->amount = p.amount;
}
