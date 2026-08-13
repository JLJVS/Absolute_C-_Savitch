#include <iostream>
using std::cout, std::endl;

void print_n(int n){
    for (int i=0; i< n; i++){
        cout << "*";
    }
    cout << endl;
}

int main()
{
    print_n(3);
    print_n(5);
    print_n(7);
    return 0;
}