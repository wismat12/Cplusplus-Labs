#ifndef KWADRAT_H_INCLUDED
#define KWADRAT_H_INCLUDED
using namespace std;

class Kwadrat: public Ksztalt
{
public:
    virtual void rysuj()
    {
        double edg = 20;
        for(int i = 0;i <= edg;i++)
        {
            for(int j = 0;j <= edg;j++)
            {
                cout.width(2);
                if(((i == 0)||(i == edg))||(((j == 0)||(j == edg))&&((i != 0)||(i != edg))))
                {
                    cout << "+";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};


#endif // KWADRAT_H_INCLUDED
