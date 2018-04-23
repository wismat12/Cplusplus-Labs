#ifndef PARA_H_INCLUDED
#define PARA_H_INCLUDED

using namespace std;

class Para
{
private:
    string word;
    int amount;
public:
    Para(string);
    Para(const Para &);

    string GetWord(){return word;}
    int GetAmount(){return amount;}

    bool operator>(const Para &);
    bool operator==(const Para &);
    bool operator<(const Para &);

    Para & operator=(const Para &);

    //Op prefiksowy ++c  c.operator++();
    Para & operator++();
    //Op postfiksowy dla c++  c.operator++(0);
    Para operator++(int);

};


#endif // PARA_H_INCLUDED
