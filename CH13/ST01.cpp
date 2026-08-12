#include <iostream>
using std::cout;
void cheers(int n);

int main() // outputs hip hip hurray
{
    cheers(3);
    return 0;
}
void cheers(int n)
{
    if (n==1){
        cout << "Hurray\n";
    }
    else {
        cout << "Hip ";
        cheers(n-1);
    }
}