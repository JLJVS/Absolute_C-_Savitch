#include <iostream>
using std::cout;

void print_reverse(int n){
    while (n > 0){
        cout << n%10;
        n /= 10;
    }
    cout << "\n";
}

int main()
{
    print_reverse(1234);
    print_reverse(3579);

    return 0;
}