#include <iostream>
using namespace std;


int main()
{
    double c {20};
    double f;


    // a
    f = (9/5) *c +32.0;
    cout << f << "\n";
    
    // b
    // Wanted to used floating point division and not integer division -> 9/5 = 1.8 instead of 9/5=1.

    // c
    f = (9.f/5.f) *c +32.0;
    cout << f << "\n";
    return 0;
}