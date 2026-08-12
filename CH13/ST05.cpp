#include <iostream>
using std::cout, std::endl;

void print_integers(int n){
    if (n==1){
        cout << n << "." << endl;
    } else {
        cout << n << ", ";
        print_integers(n-1);
    }
}

int main()
{
    print_integers(9);
    return 0;
}