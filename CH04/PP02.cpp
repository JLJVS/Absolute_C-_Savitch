#include <iostream>
using namespace std;

double areaRectangle(double b, double l){
    return b*l;
}

double perimeterRectangle(double b, double l){
    return 2*(b+l);
}

void rectangleLoop()
{
    double b {}, l {};
    while (true){
        cout << "Please enter a breadth and width for a rectangle (enter 0 for both to exit): " << endl;
        cout << "Breadth: ";
        cin >> b;
        cout << "length: ";
        cin >> l;
        if (b==l==-1){
            cout << "Goodbye " << endl;
            break;
        }
        if ((b<0) || (l < 0)){
            cout << "You entered a negative side length, please enter a valid length" << endl;
            continue;
        } 
        double area{areaRectangle(b, l)}, perimeter {perimeterRectangle(b, l)};
        cout << "The rectangle will have an area of A = " << area << ", perimeter p = " << perimeter << endl;
    }
}

int main()
{
    rectangleLoop();
    return 0;
}