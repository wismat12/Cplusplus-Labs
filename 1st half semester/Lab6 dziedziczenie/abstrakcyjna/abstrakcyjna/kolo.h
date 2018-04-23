#ifndef KOLO_H_INCLUDED
#define KOLO_H_INCLUDED
#include <cmath>
using namespace std;

struct circle
{
    double x;
    double y;
    double r;
}S;

class Kolo: public Ksztalt
{
public:
    virtual void rysuj()
    {
        S.x = 10;
        S.y = 10;
        S.r = 10;
        double crc_equation;

        for(int i = 0;i < 21;i++)
        {
            for(int j = 0;j < 21;j++)
            {
                crc_equation = (pow((j - S.x),2) + pow((i - S.y),2)) - pow(S.r,2);
                cout.width(2);

                if((crc_equation <= 0)&&(crc_equation >= -3))
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



#endif // KOLO_H_INCLUDED
