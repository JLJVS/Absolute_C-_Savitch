#include <iostream>
using namespace std;

bool AreTheyEqual(int a, int b, int c){
    return (a == b) & (b == c);
}

int main()
{
    int a {2}, b {2}, c{2}, d{3};

    cout << "a=" << a << ", b=" << b << ", c=" << c << " equal=" << AreTheyEqual(a,b,c) << endl;
    cout << "a=" << a << ", b=" << b << ", c=" << d << " equal=" << AreTheyEqual(a,b,d) << endl;

    return 0;
}