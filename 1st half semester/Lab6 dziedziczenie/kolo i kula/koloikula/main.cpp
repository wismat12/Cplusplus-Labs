#include <iostream>
#include "kolo.h"
#include "kula.h"
using namespace std;

int main()
{
    Kula k(0,0,0,10);

    cout << ((Kolo)(k)).pole();

    return 0;
}
