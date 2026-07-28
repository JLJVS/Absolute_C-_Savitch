#include <iostream>
#include "g.h"
using std::cout;
using std::endl;

namespace A
{
    void g()
    {
        cout << "Called function g:" << endl;
        cout << "You're still here? Everybody else already left!" << endl;

    }
}