#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static bool isPrimeHelper(int n){
    if (n < 2) return false;
    for (int i = 2; i < n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

static int nextPrime(int n){
    int candidate = n + 1;
    while (!isPrimeHelper(candidate)){
        candidate++;
    }
    return candidate;
}

static int prevPrime(int n){
    int candidate = n - 1;
    while (candidate >= 2){
        if (isPrimeHelper(candidate)) return candidate;
        candidate--;
    }
    return -1;   // no prime smaller than n exists
}


class PrimeNumber
{
    public:
        // constructor
        PrimeNumber(int val);
        PrimeNumber();
        // getter
        int getVal() const;
        // overload pre/post fix ++/--
        PrimeNumber& operator++() ;     // pre fix
        PrimeNumber operator++(int);   // post fix
        PrimeNumber& operator--() ;     // pre fix
        PrimeNumber operator--(int);   // post fix

    private:
        int val;
};

// constructor
PrimeNumber::PrimeNumber(int p){
    val = 1;
    if (isPrimeHelper(p)){
        val = p;
    } 
}

PrimeNumber::PrimeNumber() : PrimeNumber(1){}

// getter
int PrimeNumber::getVal() const{
    return val;
}


// prefix ++: move to next larger prime, return reference to updated *this
PrimeNumber& PrimeNumber::operator++(){
    val = nextPrime(val);
    return *this;
}
 
// postfix ++: return a copy of the old value, then update *this
PrimeNumber PrimeNumber::operator++(int){
    PrimeNumber old = *this;
    val = nextPrime(val);
    return old;
}


// prefix --: move to next smaller prime; if none exists, stay put and print a message
PrimeNumber& PrimeNumber::operator--(){
    int p = prevPrime(val);
    if (p == -1){
        cout << "No prime smaller than " << val << " exists; staying at " << val << ".\n";
    } else {
        val = p;
    }
    return *this;
}
 
// postfix --: return a copy of the old value; if no smaller prime exists, stay put and print a message
PrimeNumber PrimeNumber::operator--(int){
    PrimeNumber old = *this;
    int p = prevPrime(val);
    if (p == -1){
        cout << "No prime smaller than " << val << " exists; staying at " << val << ".\n";
    } else {
        val = p;
    }
    return old;
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
 
    // --- Constructors: happy path ---
    check(PrimeNumber(2).getVal() == 2, "constructor: 2 is prime, stays 2");
    check(PrimeNumber(7).getVal() == 7, "constructor: 7 is prime, stays 7");
    check(PrimeNumber(17).getVal() == 17, "constructor: 17 is prime, stays 17");
 
    // --- Constructors: non-prime collapses to 1 (confirmed design) ---
    check(PrimeNumber(9).getVal() == 1, "constructor: 9 (composite) collapses to 1");
    check(PrimeNumber(1).getVal() == 1, "constructor: 1 stays 1");
    check(PrimeNumber().getVal() == 1, "default constructor gives 1");
 
    // --- Constructors: edge cases (regression check for the p<=0 bug) ---
    check(PrimeNumber(0).getVal() == 1, "constructor: 0 collapses to 1, not treated as prime");
    check(PrimeNumber(-5).getVal() == 1, "constructor: negative input collapses to 1, not treated as prime");
 
    // --- Prefix ++ ---
    {
        PrimeNumber p(2);
        ++p;
        check(p.getVal() == 3, "prefix ++: 2 -> 3");
    }
    {
        PrimeNumber p(7);
        ++p;
        check(p.getVal() == 11, "prefix ++: 7 -> 11 (skips composite 8, 9, 10)");
    }
    {
        PrimeNumber p(1); // sentinel value
        ++p;
        check(p.getVal() == 2, "prefix ++ from sentinel 1 goes to 2");
    }
    {
        // chained prefix ++
        PrimeNumber p(2);
        ++p; ++p; ++p; ++p;
        check(p.getVal() == 11, "chained prefix ++ walks 2->3->5->7->11");
    }
 
    // --- Postfix ++ ---
    {
        PrimeNumber p(2);
        PrimeNumber old = p++;
        check(old.getVal() == 2 && p.getVal() == 3,
              "postfix ++: returns old value (2), updates object to 3");
    }
 
    // --- Prefix -- ---
    {
        PrimeNumber p(5);
        --p;
        check(p.getVal() == 3, "prefix --: 5 -> 3");
    }
    {
        PrimeNumber p(3);
        --p;
        check(p.getVal() == 2, "prefix --: 3 -> 2");
    }
 
    // --- Postfix -- ---
    {
        PrimeNumber p(5);
        PrimeNumber old = p--;
        check(old.getVal() == 5 && p.getVal() == 3,
              "postfix --: returns old value (5), updates object to 3");
    }
 
    // --- Edge case: -- at the smallest prime (2) stays put and prints a message ---
    {
        PrimeNumber p(2);
        ostringstream captured;
        streambuf* oldBuf = cout.rdbuf(captured.rdbuf()); // redirect cout
        --p;
        cout.rdbuf(oldBuf); // restore cout
 
        check(p.getVal() == 2, "prefix -- at 2 stays at 2");
        check(captured.str().find("No prime smaller") != string::npos,
              "prefix -- at 2 prints a message explaining why");
    }
 
    // --- Edge case: -- at the sentinel value 1 also has no smaller prime ---
    {
        PrimeNumber p(1);
        ostringstream captured;
        streambuf* oldBuf = cout.rdbuf(captured.rdbuf());
        --p;
        cout.rdbuf(oldBuf);
 
        check(p.getVal() == 1, "prefix -- at sentinel 1 stays at 1");
        check(captured.str().find("No prime smaller") != string::npos,
              "prefix -- at 1 also prints a message");
    }
 
    cout << "\n" << passed << "/" << total << " checks passed\n";
    return (passed == total) ? 0 : 1;
}
