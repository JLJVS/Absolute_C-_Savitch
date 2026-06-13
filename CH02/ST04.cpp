#include <iostream>
using namespace std;

float quadratic(float x){
    return x*x - 4*x +3;
}


int main()
{
    // x^2 - 4x + 3
    // x^2 - 4x + 3 = 0 -> (x-3)(x-1)
    // check three values x = 5, x = 2, x = 0

    float x{5}, y{2}, z{0};
    cout << "x= " << x << ": " << (quadratic(x) > 0) << endl;
    cout << "y= " << y << ": " << (quadratic(y) > 0) << endl;
    cout << "z= " << z << ": " << (quadratic(z) > 0) << endl;

    return 0;
}