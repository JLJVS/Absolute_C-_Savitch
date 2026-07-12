#include <iostream>
#include <sstream>
using namespace std;


class Complex
{
    public: 
    // constructors
        Complex(double r, double im);
        Complex(double realPart);
        Complex();
        // getters
        double getReal() const;
        double getImag() const;
        // setters
        void setReal(double re);
        void setImag(double im);
        // overload operators
        bool operator ==(const Complex& c2) const;
        const Complex operator +(const Complex& c2) const;
        const Complex operator -(const Complex& c2) const;
        const Complex operator *(const Complex& c2) const;
        // input/output operators
        friend ostream& operator<<(ostream& out, const Complex& c);
        friend istream& operator>>(istream& in, Complex& c);


    private:
        double real;
        double imag;
};

const Complex i(0,1);

// constructors
Complex::Complex(double r, double im){
    real = r;
    imag = im;
}
Complex::Complex(double realpart){
    real = realpart;
    imag = 0;
}
Complex::Complex(){
    real = 0;
    imag = 0;
}

// getters/setters
double Complex::getReal() const{
    return real;
}
double Complex::getImag() const{
    return imag;
}
void Complex::setReal(double re){
    real = re;
}
void Complex::setImag(double im){
    imag = im;
}

// overload operators
bool Complex::operator ==(const Complex& c2) const
{
    return (real==c2.real)&&(imag==c2.imag);
}
const Complex Complex::operator +(const Complex& c2) const{
    return Complex(real + c2.real, imag + c2.imag);
}
const Complex Complex::operator -(const Complex& c2) const{
    return Complex(real - c2.real, imag - c2.imag);
};
const Complex Complex::operator *(const Complex& c2) const
{
    return Complex(real*c2.real - imag*c2.imag, real*c2.imag + imag*c2.real);
};
// input/output operators
ostream& operator<<(ostream& out, const Complex& c){
    out << c.real <<" + " << c.imag <<"i";
    return out;
}
istream& operator>>(istream& in, Complex& c){
    double re{}, im{};
    char operation;
    in >> re >> operation >> im;

    if ((operation != '+') && (operation != '-')) {  // FIXED: was || (always true)
        in.setstate(ios::failbit);
        return in;
    }

    if (operation == '-'){
        im *= -1;
    }
    c.real = re;
    c.imag = im;
    return in;
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
    Complex defaultC;
    check(defaultC.getReal() == 0 && defaultC.getImag() == 0,
          "default constructor gives 0 + 0i");
 
    Complex realOnly(5.0);
    check(realOnly.getReal() == 5.0 && realOnly.getImag() == 0,
          "single-arg constructor sets real, imag defaults to 0");
 
    Complex both(3.0, 4.0);
    check(both.getReal() == 3.0 && both.getImag() == 4.0,
          "two-arg constructor sets real and imag");
 
    // --- Getters/setters ---
    Complex mutable_c;
    mutable_c.setReal(-2.5);
    mutable_c.setImag(7.5);
    check(mutable_c.getReal() == -2.5 && mutable_c.getImag() == 7.5,
          "setters update real and imag");
 
    // --- operator== ---
    check(Complex(1, 2) == Complex(1, 2), "== true for equal values");
    check(!(Complex(1, 2) == Complex(1, 3)), "== false when imag differs");
    check(!(Complex(1, 2) == Complex(2, 2)), "== false when real differs");
 
    // --- operator+ ---
    check(Complex(1, 2) + Complex(3, 4) == Complex(4, 6),
          "+ adds real and imaginary parts");
    check(Complex(1, 2) + Complex(-1, -2) == Complex(0, 0),
          "+ handles cancellation to zero");
 
    // --- operator- ---
    check(Complex(5, 5) - Complex(2, 3) == Complex(3, 2),
          "- subtracts real and imaginary parts");
    check(Complex(0, 0) - Complex(3, 4) == Complex(-3, -4),
          "- produces negative result correctly");
 
    // --- operator* (includes classic i*i == -1 identity) ---
    check(Complex(1, 2) * Complex(3, 4) == Complex(-5, 10),
          "* computes complex product correctly");
    check(i * i == Complex(-1, 0),
          "* edge case: i * i == -1");
    check(Complex(2, 0) * Complex(3, 0) == Complex(6, 0),
          "* two real numbers behaves like real multiplication");
    check(Complex(0, 3) * Complex(0, 4) == Complex(-12, 0),
          "* two pure imaginaries gives negative real result");
 
    // --- operator<< ---
    {
        ostringstream oss;
        oss << Complex(3, 4);
        check(oss.str() == "3 + 4i", "<< formats as \"3 + 4i\"");
    }
    {
        ostringstream oss;
        oss << Complex(-1, -2);
        check(oss.str() == "-1 + -2i", "<< formats negative imag as \"+ -2i\"");
    }
 
    // --- operator>> happy path ---
    {
        istringstream iss("3+4");
        Complex c;
        iss >> c;
        check(!iss.fail() && c == Complex(3, 4), ">> parses \"3+4\" correctly");
    }
    {
        istringstream iss("3 + 4");   // spaces are fine; >> skips whitespace
        Complex c;
        iss >> c;
        check(!iss.fail() && c == Complex(3, 4), ">> parses \"3 + 4\" with spaces");
    }
    {
        istringstream iss("5-3");
        Complex c;
        iss >> c;
        check(!iss.fail() && c == Complex(5, -3), ">> negates imag on '-' operator");
    }
    {
        istringstream iss("0+0");
        Complex c;
        iss >> c;
        check(!iss.fail() && c == Complex(0, 0), ">> parses all-zero input");
    }
 
    // --- operator>> edge cases: malformed input ---
    {
        istringstream iss("5x3");   // invalid operation character
        Complex c;
        iss >> c;
        check(iss.fail(), ">> sets failbit on invalid operation character");
    }
    {
        istringstream iss("abc");   // not even numeric
        Complex c;
        iss >> c;
        check(iss.fail(), ">> sets failbit on non-numeric input");
    }
 
    cout << "\n" << passed << "/" << total << " checks passed\n";
    return (passed == total) ? 0 : 1;
}
