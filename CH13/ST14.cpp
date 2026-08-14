#include <iostream>
using std::cout, std::endl;

double power(int x, int n){
    if (n<0){
        return power(x, n+1)/x;
    } else if (n==0){
        return 1;
    } else {
        return power(x, n-1)*x;
    }
}

int main()
{
    cout << power(2, 3) << endl;
    cout << power(2, -3) << endl;
    cout << power(3, 4) << endl;
    cout << power(3, -2) << endl;

    return 0;
}