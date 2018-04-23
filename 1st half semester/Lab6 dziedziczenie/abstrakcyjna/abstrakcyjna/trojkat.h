#ifndef TROJKAT_H_INCLUDED
#define TROJKAT_H_INCLUDED
using namespace std;

class Trojkat: public Ksztalt
{
public:
    virtual void rysuj()
    {
        int k = 0;
        int base = 21;
        int center = 11;

        for(int i = 1;i <= center;i++)
        {
            for(int j = 1;j <= base;j++)
            {
                cout.width(2);
                if(k == (center - 1))
                {
                    cout << "*";
                }
                else
                {
                    if((j==(center - k))||(j==(center + k)))
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            k++;
            cout << endl << endl;
        }
    }
};



#endif // TROJKAT_H_INCLUDED
