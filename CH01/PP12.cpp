#include <iostream>
using namespace std;

int main(void)
{
    int feet, inches;
    float weight;

    cout << "Please enter your height in feet and inches: ";
    cin >> feet >> inches;

    if (feet < 5){
        cout << "Sorry short king/queen, you have to be 5 feet tall for this formula to work." << endl;
        return 0;
    }

    weight = 110 + (feet - 5)*12*5 + inches*5;
    cout << "For your height, the ideal weight is " << weight << " lbs." << endl;

    return 0;
}