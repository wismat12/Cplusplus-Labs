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

    void inc();
    string GetWord(){return word;}
    int GetAmount(){return amount;}
    void print();

    bool operator>(const Para &);
    bool operator==(const Para &);
    bool operator<(const Para &);

    void operator=(const Para &);
    void operator++();

};


#endif // PARA_H_INCLUDED
