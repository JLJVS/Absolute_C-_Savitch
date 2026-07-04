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
        double amount {};
};

// setters
void Money::set_dollar(int d){
    amount += d;
}
void Money::set_cents(int c){
    amount += (double) c/100.0;
    
}
// getters
int Money::get_dollars(){
    return (int) amount/1;
}
int Money::get_cents(){
    return (int) (amount*100)%100;
}
double Money::get_amount(){
    return amount;
}

int main()
{
    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1 ===\n";
    Money m1;

    m1.set_dollar(5);
    m1.set_cents(75);

    cout << "Inputs: dollars = 5, cents = 75\n";
    cout << "Expected dollars: 5\n";
    cout << "Expected cents: 75\n";
    cout << "Expected amount: 5.75\n";

    cout << "Actual dollars: " << m1.get_dollars() << endl;
    cout << "Actual cents: " << m1.get_cents() << endl;
    cout << "Actual amount: " << m1.get_amount() << endl << endl;


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2 ===\n";
    Money m2;

    m2.set_dollar(0);
    m2.set_cents(99);

    cout << "Inputs: dollars = 0, cents = 99\n";
    cout << "Expected dollars: 0\n";
    cout << "Expected cents: 99\n";
    cout << "Expected amount: 0.99\n";

    cout << "Actual dollars: " << m2.get_dollars() << endl;
    cout << "Actual cents: " << m2.get_cents() << endl;
    cout << "Actual amount: " << m2.get_amount() << endl << endl;


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3 ===\n";
    Money m3;

    m3.set_dollar(12);
    m3.set_cents(5);

    cout << "Inputs: dollars = 12, cents = 5\n";
    cout << "Expected dollars: 12\n";
    cout << "Expected cents: 5\n";
    cout << "Expected amount: 12.05\n";

    cout << "Actual dollars: " << m3.get_dollars() << endl;
    cout << "Actual cents: " << m3.get_cents() << endl;
    cout << "Actual amount: " << m3.get_amount() << endl << endl;

    return 0;
}

