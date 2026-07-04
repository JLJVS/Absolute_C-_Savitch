#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b > a){
        int temp = a;
        a = b;
        b = temp;
    }
    while (b!=0){
        int temp = a;
        a = b;
        b = temp%b;
    }
    return a;
}

class Fraction
{
    public:
        void set_numerator(int n);
        void set_denominator(int n);
        void reduce();
    private:
        int numerator;
        int denominator;
};

void Fraction::set_numerator(int n){
    numerator = n;
}
void Fraction::set_denominator(int n){
    denominator = n;
}
void Fraction::reduce(){
    int a = numerator;
    int b = denominator;
    int common = gcd(a,b);
    cout << a/common << "/" << b/common << endl;
}

int main()
{
    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1 ===\n";
    Fraction f1;
    f1.set_numerator(8);
    f1.set_denominator(12);

    cout << "Input: 8/12\n";
    cout << "Expected output: 2/3\n";
    cout << "Actual output: ";
    f1.reduce();
    cout << "\n";


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2 ===\n";
    Fraction f2;
    f2.set_numerator(150);
    f2.set_denominator(35);

    cout << "Input: 150/35\n";
    cout << "Expected output: 30/7\n";
    cout << "Actual output: ";
    f2.reduce();
    cout << "\n";


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3 ===\n";
    Fraction f3;
    f3.set_numerator(81);
    f3.set_denominator(108);

    cout << "Input: 81/108\n";
    cout << "Expected output: 3/4\n";
    cout << "Actual output: ";
    f3.reduce();
    cout << "\n";

    return 0;
}
