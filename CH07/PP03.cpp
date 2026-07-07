#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter();
        Counter(int n);
        void reset();
        void incr1();
        void incr10();
        void incr100();
        void incr1000();
        void display();
    private:
        int count;
        bool overflow;
};

Counter::Counter(int n){
    count = n;
    overflow = false;

    if (n > 9999){
        overflow = true;
        count %= 10000;
    }
    
}
Counter::Counter(){
    Counter(0);
}
void Counter::reset(){
    count = 0;
    overflow = false;
}
void Counter::incr1(){
    count++;
    if (count > 9999) {
        overflow = true;
        count = 0;
    }
    
}
void Counter::incr10(){
    count += 10;
    if (count > 9999) {
        overflow = true;
        count = count%10000;
    } 
}
void Counter::incr100(){
    count += 100;
    if (count > 9999) {
        overflow = true;
        count = count%10000;
    } 
}
void Counter::incr1000(){
    count += 1000;
    if (count > 9999) {
        overflow = true;
        count = count%10000;
    } 
}
void Counter::display(){
    cout << "Current count: " << count << ", overflow = " << overflow << endl;
}

int main() {
    // Test default constructor
    cout << "-- Default constructor --" << endl;
    Counter c1;
    c1.display();  // expect count = 0, overflow = false

    // Test parameterized constructor, no overflow
    cout << "\n-- Constructor with n = 500 --" << endl;
    Counter c2(500);
    c2.display();  // expect count = 500, overflow = false

    // Test parameterized constructor, triggers overflow
    cout << "\n-- Constructor with n = 12345 --" << endl;
    Counter c3(12345);
    c3.display();  // expect count = 2345, overflow = true

    // Test incr1
    cout << "\n-- incr1() five times from 0 --" << endl;
    Counter c4;
    for (int i = 0; i < 5; i++) c4.incr1();
    c4.display();  // expect count = 5, overflow = false

    // Test incr10
    cout << "\n-- incr10() three times from 0 --" << endl;
    Counter c5;
    for (int i = 0; i < 3; i++) c5.incr10();
    c5.display();  // expect count = 30, overflow = false

    // Test incr100
    cout << "\n-- incr100() twice from 0 --" << endl;
    Counter c6;
    c6.incr100();
    c6.incr100();
    c6.display();  // expect count = 200, overflow = false

    // Test incr1000
    cout << "\n-- incr1000() nine times from 0 (triggers overflow) --" << endl;
    Counter c7;
    for (int i = 0; i < 9; i++) c7.incr1000();
    c7.display();  // expect count = 9000 -> after 10th would overflow; 9 times = 9000, no overflow yet

    // Force overflow with incr1000
    cout << "\n-- incr1000() ten times from 0 (triggers overflow) --" << endl;
    Counter c8;
    for (int i = 0; i < 10; i++) c8.incr1000();
    c8.display();  // expect count = 0, overflow = true

    // Test incr1 overflow boundary
    cout << "\n-- Counter(9999) then incr1() --" << endl;
    Counter c9(9999);
    c9.incr1();
    c9.display();  // expect count = 0, overflow = true

    // Test reset
    cout << "\n-- reset() after overflow --" << endl;
    c9.reset();
    c9.display();  // expect count = 0, overflow = false

    return 0;
}