#include <iostream>
using namespace std;


/*
2 < x < 3
results in a boolean so:
2 < x < 3 -> (2 < x) < 3 -> (True/False) < 3 -> (0/1) < 3 -> 1 = True

*/

int main(void)
{
    float x{2.5}, y{3.5};

    cout << "2 < " << x << " < 3 = " << ((2 < x) && (x < 3));
    cout << endl;
    cout << "2 < " << y << " < 3 = " << ((2 < y) && (y < 3));

    return 0;
}