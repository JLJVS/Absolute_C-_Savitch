
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using std::cout, std::string, std::ostream, std::istream;


class Polynomial
{
public:
    Polynomial();                                // the zero polynomial
    Polynomial(int constant);                    // a0            (NOT explicit)
    Polynomial(int coefficient, int exponent);   // a*x^n
    Polynomial(const Polynomial& other);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& rhs);

    int evaluate(int x) const;
    int degree() const;

    friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
    friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
    friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);

    friend ostream& operator<<(ostream& out, const Polynomial& p);
    friend istream& operator>>(istream& in, Polynomial& p);

private:
    struct Term
    {
        int   coefficient;
        int   exponent;
        Term* next;
    };

    void insertTerm(int coefficient, int exponent);   // maintains the invariant
    void clear();

    Term* head;
};


// ============================================================ YOUR CODE =====

Polynomial::Polynomial() : head(nullptr) { /* TODO */ }

Polynomial::Polynomial(int constant) : head(nullptr) { (void)constant; /* TODO */ }

Polynomial::Polynomial(int coefficient, int exponent) : head(nullptr)
{ (void)coefficient; (void)exponent; /* TODO */ }

Polynomial::Polynomial(const Polynomial& other) : head(nullptr) { (void)other; /* TODO */ }

Polynomial::~Polynomial() { /* TODO */ }

Polynomial& Polynomial::operator=(const Polynomial& rhs) { (void)rhs; /* TODO */ return *this; }

void Polynomial::clear() { /* TODO */ }

void Polynomial::insertTerm(int coefficient, int exponent)
{ (void)coefficient; (void)exponent; /* TODO */ }

int Polynomial::evaluate(int x) const { (void)x; /* TODO */ return 0; }

int Polynomial::degree() const { /* TODO */ return 0; }

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{ (void)lhs; (void)rhs; /* TODO */ return Polynomial{}; }

Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
{ (void)lhs; (void)rhs; /* TODO */ return Polynomial{}; }

Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
{ (void)lhs; (void)rhs; /* TODO */ return Polynomial{}; }

ostream& operator<<(ostream& out, const Polynomial& p) { (void)p; /* TODO */ return out; }

istream& operator>>(istream& in, Polynomial& p) { (void)p; /* TODO */ return in; }

// ============================================================================


// -------------------------------------------------------------- testing ----

static int failures = 0;

string str(const Polynomial& p) { std::ostringstream o; o << p; return o.str(); }

Polynomial parse(const string& s) { std::istringstream i(s); Polynomial p; i >> p; return p; }

void checkStr(const char* label, const string& got, const string& want)
{
    const bool ok = (got == want);
    if (!ok) ++failures;
    cout << (ok ? "  ok   " : "  FAIL ") << label << "  \"" << got << "\"";
    if (!ok) cout << "   expected  \"" << want << "\"";
    cout << "\n";
}

void checkInt(const char* label, int got, int want)
{
    const bool ok = (got == want);
    if (!ok) ++failures;
    cout << (ok ? "  ok   " : "  FAIL ") << label << "  " << got;
    if (!ok) cout << "   expected  " << want;
    cout << "\n";
}

int main()
{
    cout << "--- 1. constructors and output ---\n";
    checkStr("default (zero)   ", str(Polynomial{}),        "0");
    checkStr("constant 5       ", str(Polynomial{5}),       "5");
    checkStr("single term 3x^4 ", str(Polynomial{3, 4}),    "3x^4");
    checkStr("negative constant", str(Polynomial{-8}),      "-8");
    checkStr("zero coefficient ", str(Polynomial{0, 7}),    "0");   // must not store it

    cout << "\n--- 2. parsing, and round-tripping the book's examples ---\n";
    checkStr("plain            ", str(parse("3x^4 + 7x^2 + 5")),      "3x^4 + 7x^2 + 5");
    checkStr("leading minus    ", str(parse("-7x^4 + 5x^2 + 9")),     "-7x^4 + 5x^2 + 9");
    checkStr("internal minus   ", str(parse("3x^5 - 7x^3 + 2x^1 - 8")),
                                                              "3x^5 - 7x^3 + 2x^1 - 8");
    checkStr("omits zero terms ", str(parse("12x^8 + 3x^2 + 0")),     "12x^8 + 3x^2");
    checkStr("explicit zeros   ", str(parse("3x^4 + 0x^3 + 7x^2 + 0x^1 + 5")),
                                                              "3x^4 + 7x^2 + 5");
    checkStr("out of order in  ", str(parse("5 + 3x^4 + 7x^2")),      "3x^4 + 7x^2 + 5");

    cout << "\n--- 3. degree ---\n";
    checkInt("degree of 3x^4.. ", parse("3x^4 + 7x^2 + 5").degree(), 4);
    checkInt("degree of 5      ", Polynomial{5}.degree(),            0);
    checkInt("degree of zero   ", Polynomial{}.degree(),             0);

    cout << "\n--- 4. evaluate ---\n";
    const Polynomial a = parse("3x^4 + 7x^2 + 5");
    checkInt("a(2) = 48+28+5   ", a.evaluate(2), 81);
    checkInt("a(0) = 5         ", a.evaluate(0), 5);
    checkInt("a(1) = 15        ", a.evaluate(1), 15);
    checkInt("a(-1) = 15       ", a.evaluate(-1), 15);
    checkInt("zero poly at 9   ", Polynomial{}.evaluate(9), 0);

    cout << "\n--- 5. copy constructor and assignment ---\n";
    {
        Polynomial original = parse("2x^3 + 1");
        Polynomial copied{original};
        checkStr("copy matches     ", str(copied), "2x^3 + 1");
        copied = copied + Polynomial{5};
        checkStr("copy changed     ", str(copied),   "2x^3 + 6");
        checkStr("original intact  ", str(original), "2x^3 + 1");

        Polynomial assigned;
        assigned = original;
        checkStr("assigned         ", str(assigned), "2x^3 + 1");
        assigned = assigned;                      // self-assignment
        checkStr("self-assigned    ", str(assigned), "2x^3 + 1");
    }

    cout << "\n--- 6. arithmetic ---\n";
    const Polynomial b = parse("-7x^4 + 5x^2 + 9");
    checkStr("a + b            ", str(a + b), "-4x^4 + 12x^2 + 14");
    checkStr("a - a  cancels   ", str(a - a), "0");
    checkStr("a - b            ", str(a - b), "10x^4 + 2x^2 - 4");
    checkStr("zero + a         ", str(Polynomial{} + a), "3x^4 + 7x^2 + 5");

    const Polynomial xPlus1  = parse("1x^1 + 1");
    const Polynomial xMinus1 = parse("1x^1 - 1");
    checkStr("(x+1)(x-1)       ", str(xPlus1 * xMinus1), "1x^2 - 1");
    checkStr("(x+1)^2          ", str(xPlus1 * xPlus1),  "1x^2 + 2x^1 + 1");
    checkStr("a * zero         ", str(a * Polynomial{}), "0");
    checkStr("a * 2            ", str(a * Polynomial{2}), "6x^4 + 14x^2 + 10");

    cout << "\n--- 7. implicit conversion from int (both sides) ---\n";
    checkStr("a + 5            ", str(a + 5), "3x^4 + 7x^2 + 10");
    checkStr("5 + a            ", str(5 + a), "3x^4 + 7x^2 + 10");
    checkStr("2 * a            ", str(2 * a), "6x^4 + 14x^2 + 10");

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}