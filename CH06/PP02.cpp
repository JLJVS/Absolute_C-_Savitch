#include <iostream>
using namespace std;

class Counter
{
    public:
        void set_count(int count);
        int get_count();
        void increment_count();
        void decrement_count();
        void output_count();
    private:
        int current_count;
};

void Counter::set_count(int count){
    current_count = count;
}
int Counter::get_count(){
    return current_count;
}
void Counter::increment_count(){
    current_count++;
}
void Counter::decrement_count(){
    if (current_count > 0){
        current_count--;
    }
}
void Counter::output_count(){
    cout << "The current count is: " << Counter::get_count() << endl;
}

int main()
{
    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1 ===\n";
    Counter c1;
    c1.set_count(0);
    cout << "Initial: 0\n";
    cout << "Operations: increment x2\n";
    cout << "Expected: 2\n";
    c1.increment_count();
    c1.increment_count();
    cout << "Actual: ";
    c1.output_count();
    cout << "\n";


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2 ===\n";
    Counter c2;
    c2.set_count(10);
    cout << "Initial: 10\n";
    cout << "Operations: decrement x3\n";
    cout << "Expected: 7\n";
    c2.decrement_count();
    c2.decrement_count();
    c2.decrement_count();
    cout << "Actual: ";
    c2.output_count();
    cout << "\n";


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3 ===\n";
    Counter c3;
    c3.set_count(1);
    cout << "Initial: 1\n";
    cout << "Operations: decrement x2 (second should not go below 0)\n";
    cout << "Expected: 0\n";
    c3.decrement_count();
    c3.decrement_count();   // should stay at 0
    cout << "Actual: ";
    c3.output_count();
    cout << "\n";

    return 0;
}