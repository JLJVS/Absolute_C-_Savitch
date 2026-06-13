#include <iostream>
using namespace std;

int main()
{
    // x^2 - x - 2 > 0
    // (x-2)(x+1) > 0 
    // so x = 2 or x = -1

    float x{3}, y{0}, z{-2};
    cout << "x = " << x << ": " <<(x*x - x - 2 > 0) << endl;
    cout << "y = " << y << ": " << (y*y - y - 2 > 0) << endl;
    cout << "z = " << z << ": " << (z*z - z - 2 > 0) << endl;

    return 0;
}