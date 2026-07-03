#include <iostream>
using namespace std;

class Point
{
    public:
        void set(double x, double y);
        void move(double x, double y);
        void rotate();

        double get_x() const;
        double get_y() const;
    private:
        double x;
        double y;

};

void Point::set(double new_x, double new_y){
    x = new_x;
    y = new_y;
}
void Point::move(double dx, double dy){
    x += dx;
    y += dy;
}
void Point::rotate(){
    double temp = y;
    y = x;
    x = -temp;
}
double Point::get_x() const{
    return x;
}
double Point::get_y() const{
    return y;
}

int main()
{
    // ---------- Test Case 1: Basic set ----------
    cout << "=== Test Case 1 ===\n";
    Point p1;
    p1.set(3, 4);
    cout << "Set to (3, 4)\n";
    cout << "Expected: (3, 4)\n";
    cout << "Actual: (" << p1.get_x() << ", " << p1.get_y() << ")\n\n";


    // ---------- Test Case 2: Move the point ----------
    cout << "=== Test Case 2 ===\n";
    Point p2;
    p2.set(0, 0);
    p2.move(5, -2);
    cout << "Start at (0, 0), move by (5, -2)\n";
    cout << "Expected: (5, -2)\n";
    cout << "Actual: (" << p2.get_x() << ", " << p2.get_y() << ")\n\n";


    // ---------- Test Case 3: Rotate a point ----------
    cout << "=== Test Case 3 ===\n";
    Point p3;
    p3.set(2, 3);
    p3.rotate();   // rotation: (x, y) → (-y, x)
    cout << "Rotate (2, 3)\n";
    cout << "Expected: (-3, 2)\n";
    cout << "Actual: (" << p3.get_x() << ", " << p3.get_y() << ")\n\n";


    // ---------- Test Case 4: Move + Rotate ----------
    cout << "=== Test Case 4 ===\n";
    Point p4;
    p4.set(1, 1);
    p4.move(2, 3);   // now (3, 4)
    p4.rotate();     // now (-4, 3)
    cout << "Start at (1, 1), move by (2, 3), rotate\n";
    cout << "Expected: (-4, 3)\n";
    cout << "Actual: (" << p4.get_x() << ", " << p4.get_y() << ")\n\n";


    // ---------- Test Case 5: Multiple rotations ----------
    cout << "=== Test Case 5 ===\n";
    Point p5;
    p5.set(5, 0);

    // Apply rotate 4 times → full 360° rotation
    p5.rotate(); // (0, 5)
    p5.rotate(); // (-5, 0)
    p5.rotate(); // (0, -5)
    p5.rotate(); // (5, 0)

    cout << "Rotate (5, 0) four times\n";
    cout << "Expected: (5, 0)\n";
    cout << "Actual: (" << p5.get_x() << ", " << p5.get_y() << ")\n\n";

    return 0;
}
