#include <iostream>
#include <sstream>
using namespace std;

int gcd(int a, int b){
    if (b > a){
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0){
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

class Rational
{
    public:
        // constructors
        Rational(int num, int den);
        Rational(int wholeNumber);
        Rational();
        // equalities
        bool operator == (const Rational& r2) const;
        bool operator < (const Rational& r2) const;
        bool operator <= (const Rational& r2) const;
        bool operator > (const Rational& r2) const;
        bool operator >= (const Rational& r2) const;
        // math operators
        const Rational operator +(const Rational& r2) const;
        const Rational operator -(const Rational& r2) const;
        const Rational operator *(const Rational& r2) const;
        const Rational operator /(const Rational& r2) const;
        // io operators
        friend ostream& operator<<(ostream& out, const Rational& r);
        friend istream& operator>>(istream& in, Rational& r);
    private:
        int numerator;
        int denominator;
};

// constructors
Rational::Rational(int num, int den){
    numerator = num;
    denominator = den;
}

Rational::Rational(int wholeNumber){
    numerator = wholeNumber;
    denominator = 1;
}

Rational::Rational(){
    numerator = 0;
    denominator = 1;
}

// equalities
bool Rational::operator == (const Rational& r2) const{
    int f1 {gcd(numerator, denominator)}, f2 {gcd(r2.numerator, r2.denominator)};
    return (numerator/f1 == r2.numerator/f2) && (denominator/f1 == r2.denominator/f2);
}

bool Rational::operator > (const Rational& r2) const{
    int f1 {gcd(numerator, denominator)}, f2 {gcd(r2.numerator, r2.denominator)};
    double frac1 = static_cast<double>(numerator/f1) / (denominator/f1);
    double frac2 = static_cast<double>(r2.numerator/f2) / (r2.denominator/f2);
    return frac1 > frac2;
}

bool Rational::operator >= (const Rational& r2) const{
    int f1 {gcd(numerator, denominator)}, f2 {gcd(r2.numerator, r2.denominator)};
    double frac1 = static_cast<double>(numerator/f1) / (denominator/f1);
    double frac2 = static_cast<double>(r2.numerator/f2) / (r2.denominator/f2);
    return frac1 >= frac2;
}

bool Rational::operator < (const Rational& r2) const{
    int f1 {gcd(numerator, denominator)}, f2 {gcd(r2.numerator, r2.denominator)};
    double frac1 = static_cast<double>(numerator/f1) / (denominator/f1);
    double frac2 = static_cast<double>(r2.numerator/f2) / (r2.denominator/f2);
}

bool Rational::operator <= (const Rational& r2) const{
    int f1 {gcd(numerator, denominator)}, f2 {gcd(r2.numerator, r2.denominator)};
    double frac1 = static_cast<double>(numerator/f1) / (denominator/f1);
    double frac2 = static_cast<double>(r2.numerator/f2) / (r2.denominator/f2);
    return frac1 <= frac2;
}

// math operators
const Rational Rational::operator +(const Rational& r2) const{
    int newNum {}, newDen {};
    newNum = numerator * r2.denominator + r2.numerator*denominator;
    newDen = denominator  * r2.denominator;
    return Rational(newNum, newDen);
}

const Rational Rational::operator -(const Rational& r2) const{
    int newNum {}, newDen {};
    newNum = numerator * r2.denominator - r2.numerator*denominator;
    newDen = denominator  * r2.denominator;
    return Rational(newNum, newDen);
}

const Rational Rational::operator *(const Rational& r2) const{
    int newNum {}, newDen {};
    newNum = numerator * r2.numerator ;
    newDen = denominator  * r2.denominator;
    return Rational(newNum, newDen);
}

const Rational Rational::operator /(const Rational& r2) const{
    int newNum {}, newDen {};
    newNum = numerator * r2.denominator;
    newDen = denominator  * r2.numerator;
    return Rational(newNum, newDen);
}

ostream& operator<<(ostream& out, const Rational& r) {
    out << r.numerator << "/" << r.denominator;
    return out;   // enables cout << r1 << " and " << r2;
}

istream& operator>>(istream& in, Rational& r) {
    int num, den;
    char slash;

    in >> num >> slash >> den;   // expects the form  3/4

    if (slash != '/') {
        in.setstate(ios::failbit);  // malformed input — let caller check with if(cin)
        return in;
    }
    if (den == 0) {
        in.setstate(ios::failbit);  // reject zero denominator
        return in;
    }

    r.numerator = num;
    r.denominator = den;
    return in;
}

int testsRun = 0;
int testsPassed = 0;
 
void check(const string& label, bool condition) {
    testsRun++;
    if (condition) {
        testsPassed++;
        cout << "[PASS] " << label << endl;
    } else {
        cout << "[FAIL] " << label << endl;
    }
}
 
// Like check(), but on failure also prints what we got vs. what we expected —
// useful for operator<< tests where the mismatch itself is the interesting part.
void checkStr(const string& label, const string& actual, const string& expected) {
    testsRun++;
    if (actual == expected) {
        testsPassed++;
        cout << "[PASS] " << label << endl;
    } else {
        cout << "[FAIL] " << label
             << "  (got \"" << actual << "\", expected \"" << expected << "\")" << endl;
    }
}

 

int main() {
    // ---- constructors ----
    Rational zero;                 // default ctor -> 0/1
    Rational whole(5);             // single-int ctor -> 5/1
    Rational half(1, 2);
    Rational quarter(1, 4);
    Rational twoQuarters(2, 4);    // reduces to 1/2
 
    check("default ctor == 0 (as whole number)", zero == Rational(0));
    check("single-int ctor == 5/1", whole == Rational(5, 1));
 
    // ---- equality (also exercises gcd reduction) ----
    check("1/2 == 2/4", half == twoQuarters);
    check("1/2 != 1/4 (sanity check, expect true)", !(half == quarter));
 
    // ---- comparisons ----
    // These are the ones affected by the bugs described above the results.
    check("1/2 > 1/4", half > quarter);
    check("1/4 < 1/2", quarter < half);
    check("1/2 >= 1/2", half >= half);
    check("1/2 <= 1/2", half <= half);
    check("1/4 >= 1/4 (not strictly greater)", quarter >= quarter);
 
    // ---- addition ----
    // 1/2 + 1/4 = 3/4
    Rational sum = half + quarter;
    check("1/2 + 1/4 == 3/4", sum == Rational(3, 4));
 
    // ---- subtraction ----
    // 1/2 - 1/4 = 1/4
    Rational diff = half - quarter;
    check("1/2 - 1/4 == 1/4", diff == quarter);
 
    // ---- multiplication ----
    // 1/2 * 1/4 = 1/8
    Rational prod = half * quarter;
    check("1/2 * 1/4 == 1/8", prod == Rational(1, 8));
 
    // ---- division ----
    // 1/2 / 1/4 = 2
    Rational quot = half / quarter;
    check("1/2 / 1/4 == 2", quot == Rational(2));
 
    // ---- chained expression ----
    // (1/2 + 1/4) - 1/4 should be back to 1/2
    check("(1/2 + 1/4) - 1/4 == 1/2", (half + quarter) - quarter == half);
 
    // ---- operator<< ----
    // Use an ostringstream instead of cout so we can capture and check the
    // text instead of eyeballing it.
    {
        ostringstream out;
        out << half;
        checkStr("1/2 prints as \"1/2\"", out.str(), "1/2");
    }
    {
        ostringstream out;
        out << whole;
        checkStr("5/1 prints as \"5/1\"", out.str(), "5/1");
    }
    {
        // chained << should work the same way it does for cout
        ostringstream out;
        out << half << " and " << quarter;
        checkStr("chained << works", out.str(), "1/2 and 1/4");
    }
 
    // ---- operator>> ----
    // istringstream lets us feed >> fixed text instead of typing at a real prompt.
    {
        istringstream in("3/4");
        Rational r;
        in >> r;
        check("parsing \"3/4\" succeeds", static_cast<bool>(in));
        check("parsing \"3/4\" gives 3/4", r == Rational(3, 4));
    }
    {
        // two fractions back to back, separated by whitespace
        istringstream in("1/2 2/3");
        Rational a, b;
        in >> a >> b;
        check("reading two fractions in a row works", a == Rational(1, 2) && b == Rational(2, 3));
    }
    {
        // malformed: missing slash
        istringstream in("34");
        Rational r;
        in >> r;
        check("parsing \"34\" (no slash) sets failbit", !in);
    }
    {
        // malformed: zero denominator
        istringstream in("5/0");
        Rational r;
        in >> r;
        check("parsing \"5/0\" sets failbit", !in);
    }
    {
        // round trip: write it out, read it back in, should be equal
        ostringstream out;
        out << Rational(7, 9);
        istringstream in(out.str());
        Rational r;
        in >> r;
        check("round-trip 7/9 through << and >>", r == Rational(7, 9));
    }
 
    cout << "\n" << testsPassed << " / " << testsRun << " tests passed." << endl;
    return 0;
}
 
