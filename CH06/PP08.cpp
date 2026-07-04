#include <iostream>
using namespace std;

class Money
{
    public:
        void set_dollar(int d);
        void set_cents(int c);
        int get_dollars();
        int get_cents();
        double get_amount();

    private:
        int dollars {};
        int cents {};
};

// setters
void Money::set_dollar(int d){
    dollars = d;
}
void Money::set_cents(int c){
    if (cents >= 100){
        dollars += cents/100;
        cents = c%100;
    } else {
        cents = c;
    }
    
}
// getters
int Money::get_dollars(){
    return dollars;
}
int Money::get_cents(){
    return cents;
}
double Money::get_amount(){
    return (double) dollars + (double) cents/100.0;
}

int main()
{
    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1 ===\n";
    Money m1;

    m1.set_dollar(5);
    m1.set_cents(75);

    cout << "Inputs: dollars = 5, cents = 75\n";
    cout << "Expected amount: 5.75\n";
    cout << "Actual amount: " << m1.get_amount() << "\n\n";


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2 ===\n";
    Money m2;

    m2.set_dollar(0);
    m2.set_cents(99);

    cout << "Inputs: dollars = 0, cents = 99\n";
    cout << "Expected amount: 0.99\n";
    cout << "Actual amount: " << m2.get_amount() << "\n\n";


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3 ===\n";
    Money m3;

    m3.set_dollar(12);
    m3.set_cents(5);

    cout << "Inputs: dollars = 12, cents = 5\n";
    cout << "Expected amount: 12.05\n";
    cout << "Actual amount: " << m3.get_amount() << "\n\n";

    return 0;
}
