#include <iostream>
using namespace std;

class MyInteger
{
    public:
        MyInteger(int v);
        MyInteger();
        int getVal() const;
        void setVal(int v);
        int operator[](int index) const;
    private:
        int val;
};

// constructors
MyInteger::MyInteger(int v){
    val = v;
}
MyInteger::MyInteger() : MyInteger(0){}

// getters and setters
int MyInteger::getVal() const {
    return val;
}
void MyInteger::setVal(int v){
    val = v;
}

//overload operator []
int MyInteger::operator[](int index) const{
    if (index < 0){
        return -1;
    }
    int copy {val};
    if (copy < 0){
        copy *= -1;
    }
    if (index == 0){
        return copy%10;
    }
    
    while (copy > 0){
        if (index == 0){
            return copy %10;
        }
        copy /= 10;
        index--;
    }
    return -1;
}


// ---------------------------------------------------------------
// main: happy-path and edge-case checks
// ---------------------------------------------------------------
 
int main(){
    int passed = 0, total = 0;
    auto check = [&](bool cond, const string& name){
        total++;
        if (cond){ passed++; cout << "[PASS] " << name << "\n"; }
        else      { cout << "[FAIL] " << name << "\n"; }
    };
 
    // --- Constructors ---
    MyInteger defaultI;
    check(defaultI.getVal() == 0, "default constructor gives 0");
 
    MyInteger v1(1234);
    check(v1.getVal() == 1234, "one-arg constructor sets value");
 
    // --- Getter/setter ---
    MyInteger mutable_i(1);
    mutable_i.setVal(42);
    check(mutable_i.getVal() == 42, "setter updates value");
 
    // --- operator[] happy path: digit-by-digit, indexed from the right ---
    MyInteger n(1234);
    check(n[0] == 4, "index 0 is the units digit (4 of 1234)");
    check(n[1] == 3, "index 1 is the tens digit (3 of 1234)");
    check(n[2] == 2, "index 2 is the hundreds digit (2 of 1234)");
    check(n[3] == 1, "index 3 is the thousands digit (1 of 1234)");
 
    // --- single-digit number ---
    MyInteger single(7);
    check(single[0] == 7, "single-digit number: index 0 returns the digit");
 
    // --- repeated digits (regression check for the earlier copy/10 bug) ---
    MyInteger repeated(5555);
    check(repeated[0] == 5 && repeated[1] == 5 &&
          repeated[2] == 5 && repeated[3] == 5,
          "repeated digits all read correctly");
 
    // --- mixed digits, confirms ordering isn't accidentally reversed ---
    MyInteger mixed(9081);
    check(mixed[0] == 1 && mixed[1] == 8 &&
          mixed[2] == 0 && mixed[3] == 9,
          "digit order is correct, including an internal 0 (9081)");
 
    // --- edge case: index out of range (beyond the number of digits) ---
    MyInteger small(12);
    check(small[5] == -1, "index beyond the number of digits returns -1");
 
    // --- edge case: negative index ---
    check(n[-1] == -1, "negative index returns -1");
 
    // --- edge case: value of zero ---
    MyInteger zero(0);
    check(zero[0] == 0, "zero value now correctly returns digit 0 at index 0");
    check(zero[1] == -1, "zero value returns -1 at any index beyond 0");
 
    // --- edge case: negative value (regression check for the val/copy bug) ---
    MyInteger neg(-123);
    check(neg[0] == 3, "negative value: index 0 returns a positive digit (3 of -123)");
    check(neg[1] == 2, "negative value: index 1 returns the correct digit (2 of -123)");
    check(neg[2] == 1, "negative value: index 2 returns the correct digit (1 of -123)");
 
    // --- edge case: negative single-digit value ---
    MyInteger negSingle(-7);
    check(negSingle[0] == 7, "negative single-digit value returns positive digit at index 0");
 
    cout << "\n" << passed << "/" << total << " checks passed\n";
    return (passed == total) ? 0 : 1;
}
 
