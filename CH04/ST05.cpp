#include <iostream>
using namespace std;

void BothValue(int &a, int &b){
    a = b = 0;
}

int main()
{
    int a {10}, b{13};
    cout << "a = " << a << ", b = " << b << endl;
    BothValue(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}