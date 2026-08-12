#include <iostream>
using std::cout, std::endl;

void print_integers(int n, int n_target){
    if (n==n_target){
        cout << n << endl;
    } else {
        cout << n << ", ";
        print_integers(n+1, n_target);
    }
}

int main()
{
    print_integers(1, 9);
    return 0;
}