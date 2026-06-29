#include <iostream>
using namespace std;

void sort(int &a, int &b, int &c){
    int first {a}, second {a}, third{a};
    
    // a largest
    if ((a >= b) && (a >= c)){
        first = a;
        if (b > c){
            second = b;
            third = c;
        } else {
            second = c;
            third = b;
        }
    // b largest
    } else if ((b > a) && (b >= c)){
        first = b;
        if (a > c){
            second = a;
            third = c;
        } else {
            second = c;
            third = a;
        }
    // c largest
    } else {
        first = c;
        if (a > b){
            second = a;
            third = b;
        } else {
            second = b;
            third = a;
        }
    }

    a = first;
    b = second;
    c = third;


}

int main() {
    int a, b, c;

    // Test case 1
    a = 3; b = 1; c = 2;
    sort(a, b, c);
    cout << "Test 1: " << a << " " << b << " " << c << endl;

    // Test case 2
    a = 10; b = 50; c = 30;
    sort(a, b, c);
    cout << "Test 2: " << a << " " << b << " " << c << endl;

    // Test case 3
    a = -1; b = -5; c = -3;
    sort(a, b, c);
    cout << "Test 3: " << a << " " << b << " " << c << endl;

    // Test case 4
    a = 7; b = 7; c = 2;
    sort(a, b, c);
    cout << "Test 4: " << a << " " << b << " " << c << endl;

    // Test case 5
    a = 100; b = 1; c = 100;
    sort(a, b, c);
    cout << "Test 5: " << a << " " << b << " " << c << endl;

    return 0;
}