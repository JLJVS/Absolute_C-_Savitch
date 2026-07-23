#include <iostream>
using namespace  std;

class TwoD{
    private:
        double* arrPointer;
        int MaxRows;
        int MaxCols;
    public:
        TwoD(); // defaults to a 10x10 matrix
        TwoD(int rows, int cols);
        ~TwoD();
        TwoD(const TwoD& twoDObject);
        TwoD& operator=(const TwoD& rtSide);
        void setElement(int row, int col, double val);
        double getElement(int row, int col) const;
        int getRows() const { return MaxRows; } // accessors so tests can verify dimensions
        int getCols() const { return MaxCols; }
        friend TwoD operator+(const TwoD& lhs, const TwoD& rhs);
};

TwoD::TwoD(int rows, int cols){
    arrPointer = new double[rows*cols];
    MaxRows = rows;
    MaxCols = cols;
}

TwoD::TwoD() : TwoD(10,10){}

TwoD::~TwoD(){
    delete [] arrPointer;
}

TwoD::TwoD(const TwoD& twoDObject) : TwoD(twoDObject.MaxRows, twoDObject.MaxCols){
    for (int i {}; i < MaxRows*MaxCols; i++){
        *(arrPointer+i) = *(twoDObject.arrPointer+i);
    }
}

TwoD& TwoD::operator=(const TwoD& rtSide){
    // guard against assigning the same element
    if (this == &rtSide) return *this;
    delete [] arrPointer;
    this-> MaxRows = rtSide.MaxRows;
    this-> MaxCols = rtSide.MaxCols;
    arrPointer = new double[rtSide.MaxRows*rtSide.MaxCols];
    for (int i {}; i < MaxRows*MaxCols; i++){
        *(arrPointer+i) = *(rtSide.arrPointer+i);
    }
    return *this;
}
void TwoD::setElement(int row, int col, double val){
    *(arrPointer+row*MaxCols+col) = val;
}
double TwoD::getElement(int row, int col) const{
    return *(arrPointer+row*MaxCols+col);
}

TwoD operator+(const TwoD& lhs, const TwoD& rhs){
    if (lhs.MaxRows == rhs.MaxRows && lhs.MaxCols == rhs.MaxCols){
        TwoD answer(lhs.MaxRows, lhs.MaxCols);
        for (int i {}; i < lhs.MaxRows*lhs.MaxCols; i++){
            *(answer.arrPointer + i) = *(lhs.arrPointer+i) + *(rhs.arrPointer+i);
        }
        return answer;
    }
    else{ // if the sizes mismatch return the left hand side
        cout << "Sizes of the two arrays dont match, returning left hand side." << endl;
        return lhs;
    }
}

int main(){
    cout << "############### TESTS FOR class TwoD ###############\n\n";

    // -------------------------------------------------------------------
    cout << "=== TEST 1: parameterized ctor + setElement / getElement ===\n";
    cout << "Uses a 2x5 (NON-square) matrix on purpose: a square matrix would\n";
    cout << "still pass even if the index formula were row*MaxRows+col instead\n";
    cout << "of row*MaxCols+col. Non-square exposes that bug.\n";
    TwoD m(2, 5);
    m.setElement(0, 0, 1.0);   // top-left corner
    m.setElement(0, 2, 5.0);   // interior of row 0
    m.setElement(1, 4, 9.0);   // bottom-right corner
    cout << "  (0,0) expected 1.0  -> got " << m.getElement(0, 0) << "\n";
    cout << "  (0,2) expected 5.0  -> got " << m.getElement(0, 2) << "\n";
    cout << "  (1,4) expected 9.0  -> got " << m.getElement(1, 4) << "\n\n";

    // -------------------------------------------------------------------
    cout << "=== TEST 2: copy constructor makes a DEEP copy ===\n";
    cout << "Copy m into mCopy, then mutate the ORIGINAL m. A deep copy must be\n";
    cout << "unaffected; if mCopy also changes, the two share one array (shallow).\n";
    TwoD mCopy(m);             // copy constructor
    m.setElement(0, 0, 99.0);  // mutate the source AFTER copying
    cout << "  original m(0,0) now 99.0        -> got " << m.getElement(0, 0) << "\n";
    cout << "  copy mCopy(0,0) should STAY 1.0 -> got " << mCopy.getElement(0, 0) << "\n";
    cout << "  (a value of 99 here would mean a SHALLOW copy = BUG)\n\n";

    // -------------------------------------------------------------------
    cout << "=== TEST 3a: operator= makes a DEEP copy ===\n";
    TwoD a(2, 2);
    a.setElement(0, 0, 7.0);
    TwoD b(2, 2);
    b = a;                     // assignment
    a.setElement(0, 0, 42.0);  // mutate source after assigning
    cout << "  after b=a, then a(0,0)=42: b(0,0) should STAY 7.0 -> got "
         << b.getElement(0, 0) << "\n\n";

    cout << "=== TEST 3b: self-assignment (a = a) must not corrupt ===\n";
    cout << "Without the (this == &rtSide) guard, this deletes a's array and then\n";
    cout << "reads from it. NOTE: it may pass by luck even when broken (freed memory\n";
    cout << "often still holds old bytes) -- the guard is proven by reasoning, not\n";
    cout << "by this one run.\n";
    a = a;
    cout << "  a(0,0) should STAY 42.0 -> got " << a.getElement(0, 0) << "\n\n";

    cout << "=== TEST 3c: assigning different dimensions updates size ===\n";
    cout << "big starts 10x10, gets assigned a 3x3. This is the exact bug we fixed:\n";
    cout << "if the loop used the OLD dimensions it would overrun the new array.\n";
    TwoD big(10, 10);
    TwoD small(3, 3);
    small.setElement(2, 2, 3.14);
    big = small;               // big must shrink to 3x3
    cout << "  big dims should be 3x3 -> got " << big.getRows() << "x" << big.getCols() << "\n";
    cout << "  big(2,2) should be 3.14 -> got " << big.getElement(2, 2) << "\n\n";

    // -------------------------------------------------------------------
    cout << "=== TEST 4a: operator+ adds element-by-element ===\n";
    cout << "Two 2x3 matrices; x holds 1..6, y holds 10..60. Return is BY VALUE,\n";
    cout << "so this also silently exercises the copy constructor.\n";
    TwoD x(2, 3), y(2, 3);
    for (int r = 0; r < 2; r++)
        for (int c = 0; c < 3; c++){
            x.setElement(r, c, r * 3 + c + 1);          // 1,2,3 / 4,5,6
            y.setElement(r, c, (r * 3 + c + 1) * 10);   // 10,20,30 / 40,50,60
        }
    TwoD sum = x + y;
    cout << "  sum(0,0) expected 11 -> got " << sum.getElement(0, 0) << "\n";
    cout << "  sum(0,2) expected 33 -> got " << sum.getElement(0, 2) << "\n";
    cout << "  sum(1,2) expected 66 -> got " << sum.getElement(1, 2) << "\n\n";

    cout << "=== TEST 4b: operator+ size mismatch returns the left operand ===\n";
    TwoD p(2, 2), q(3, 3);
    p.setElement(0, 0, 5.0);
    cout << "  (expect a mismatch warning on the next line)\n  ";
    TwoD rez = p + q;          // dimensions differ
    cout << "  rez dims should equal lhs p = 2x2 -> got "
         << rez.getRows() << "x" << rez.getCols() << "\n";
    cout << "  rez(0,0) should be 5.0 (copy of lhs) -> got " << rez.getElement(0, 0) << "\n\n";

    // -------------------------------------------------------------------
    cout << "=== TEST 5: destructor ===\n";
    cout << "Not directly assertable. Every object above is destroyed as main exits,\n";
    cout << "including all the copies and the temporary from x+y. A clean exit here\n";
    cout << "means no double-free -- i.e. the deep copies really are independent.\n";
    cout << "For rigorous proof, build with -fsanitize=address or run under valgrind.\n\n";

    cout << "############### ALL TESTS COMPLETE ###############\n";
    return 0;
}