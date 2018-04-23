#include <iostream>

using namespace std;
//void uzupelnij(int **)
void tes(int & x);
int main()
{
    //int tabliczka[10][10];
    int x=5;
    tes(x);
    cout << x << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
void tes(int & x)
{
    cout << x << endl;
    x+=5;
    cout << x << endl;
}
