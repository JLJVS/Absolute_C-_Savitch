#include <iostream>
using namespace std;

void tripler(int& n){
    n = 3*n;
}

int main()
{
    int a[3] {4, 5, 6}, number =2;
    // a
    tripler(a[2]);
    cout << "tripler(a[2])=" << a[2] << endl;
    // b this is not allowed 3 is out of bounds of the array
    tripler(a[3]);  
    cout << "tripler(a[3])=" << a[3] << endl;
    // c this is not allowed 3 is out of bounds of the array
    tripler(a[number]);
    cout << "tripler(a[number])=" << a[number] << endl;
    // d not allowed tripler expects an int not an array of ints
    // tripler(a);
    // e
    tripler(number);
    cout << "number=" << number << endl;
    
}