#include <iostream>
using namespace std;

class Vector2D
{
    public:
        // constructors
        Vector2D(int a, int b);
        Vector2D();
        // getters and setters
        double getx() const;
        double gety() const;
        void setx(int a);
        void sety(int b);
        // overloaded operators
        const Vector2D operator +(const Vector2D& v2) const;
        const Vector2D operator -(const Vector2D& v2) const;
        const int operator *(const Vector2D& v2) const;

    private:
        int x;
        int y;
};

// constructors
Vector2D::Vector2D(int a, int b){
    x = a;
    y = b;
}
Vector2D::Vector2D(): Vector2D(0,0){}


// getters and setters
double Vector2D::getx() const{
    return x;
}
double Vector2D::gety() const{
    return y;
}
void Vector2D::setx(int a){
    x = a;
}
void Vector2D::sety(int b){
    y = b;
}

// overload operators
const Vector2D Vector2D::operator +(const Vector2D& v2) const{
    return Vector2D(x + v2.x, y + v2.y);
}
const Vector2D Vector2D::operator -(const Vector2D& v2) const {
    return Vector2D(x - v2.x, y - v2.y);
}
const int Vector2D::operator *(const Vector2D& v2) const {
    return x*v2.x + y*v2.y;
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
 
    // helper since Vector2D has no operator==
    auto sameVec = [](const Vector2D& v, double ex, double ey){
        return v.getx() == ex && v.gety() == ey;
    };
 
    // --- Constructors ---
    Vector2D defaultV;
    check(sameVec(defaultV, 0, 0),
          "default constructor gives (0, 0)");
 
    Vector2D v1(3, 4);
    check(sameVec(v1, 3, 4),
          "two-arg constructor sets x and y");
 
    Vector2D negV(-2, -5);
    check(sameVec(negV, -2, -5),
          "constructor handles negative components");
 
    // --- Getters/setters ---
    Vector2D mutable_v;
    mutable_v.setx(7);
    mutable_v.sety(-3);
    check(sameVec(mutable_v, 7, -3),
          "setters update x and y independently");
 
    // --- operator+ ---
    check(sameVec(Vector2D(1, 2) + Vector2D(3, 4), 4, 6),
          "+ adds corresponding components");
    check(sameVec(Vector2D(1, 2) + Vector2D(-1, -2), 0, 0),
          "+ handles cancellation to zero vector");
    check(sameVec(Vector2D(0, 0) + defaultV, 0, 0),
          "+ zero vector plus zero vector stays zero");
 
    // --- operator- ---
    check(sameVec(Vector2D(5, 5) - Vector2D(2, 3), 3, 2),
          "- subtracts corresponding components");
    check(sameVec(Vector2D(0, 0) - Vector2D(3, 4), -3, -4),
          "- produces negative result correctly");
    check(sameVec(Vector2D(2, 2) - Vector2D(2, 2), 0, 0),
          "- vector minus itself gives zero vector");
 
    // --- operator* (dot product) ---
    check(Vector2D(1, 2) * Vector2D(3, 4) == 11,
          "* computes dot product correctly (1*3 + 2*4 = 11)");
    check(Vector2D(0, 0) * Vector2D(5, 9) == 0,
          "* dot product with zero vector is 0");
    check(Vector2D(2, 3) * Vector2D(-2, -3) == -13,
          "* dot product with opposite vector is negative");
    check(Vector2D(3, 4) * Vector2D(4, -3) == 0,
          "* dot product of perpendicular vectors is 0");
    check(Vector2D(3, 0) * Vector2D(3, 0) == 9,
          "* dot product of a vector with itself equals squared magnitude");
 
    cout << "\n" << passed << "/" << total << " checks passed\n";
    return (passed == total) ? 0 : 1;
}
