#include <iostream>
using std::cout;

void print_reverse(int n){
    if (n==0){
        cout << "\n";
    } else {
        cout << n%10;
        print_reverse(n/10);
    }    
}

int main()
{
    print_reverse(1234);
    print_reverse(3579);

    return 0;
}