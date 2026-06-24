#include <iostream>
using namespace std;

/*
We can overload unit price function by using the fact that a square pizza only needs one side and make it a double. But this makes it hard on the compiler because it doesn't know if it should use a int or a double.
*/

double unitPrice(int diameter, double price){
    const double PI = 3.14159;
    double radius, area;

    radius = diameter/double(2);
    area = PI * radius *radius;
    return (price/area);
}

double unitPrice (int length, int width, double price)
{
    double area = length * width;
    return (price/area);
}

double unitPrice(double side, double price)
{
    double area = side*side;
    return (price/area);
}