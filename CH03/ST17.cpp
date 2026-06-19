#include <iostream>
using namespace std;

void print_products(int a, int b, int c){

    cout << a*b*c << endl;
}


int main()
{
    cout << "Please enter three integers seperated by a space: ";
    int a,b,c;
    cin >> a >> b>> c;
    print_products(a,b,c);
    
    return 0;
}