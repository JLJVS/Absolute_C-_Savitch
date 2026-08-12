#include <iostream>
using std::cout;

void print_n(int n){
    if (n==0){
        cout << "\n";
    } else {
        cout << "*";
        print_n(n-1);
    }
}

int main()
{
    print_n(3);
    print_n(5);
    print_n(7);
    return 0;
}