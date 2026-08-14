#include <iostream>
using std::cout, std::endl;

int squares(int n){
    if (n==1 ){
        return 1;
    } else {
        return n*n + squares(n-1);
    }
}

int main()
{
    cout << squares(3) << endl;
    return 0;
}