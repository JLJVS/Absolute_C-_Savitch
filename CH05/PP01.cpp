#include <iostream>
#include <iomanip>
using namespace std;
using std::setprecision;

void printRainfall(float previous[], float current[])
{
    const int months {12};

    cout << "   | JAN | FEB | MAR | APR | MAY | JUN | JUL | AUG | SEP | OCT | NOV | DEC |" << endl;
    cout << "   |-----------------------------------------------------------------------|" << endl;
    cout << "AVG| ";
    float diffs[months] {};

    // print the previous avg
    for (int i {}; i < months; i++){
        cout << fixed << setprecision(1) << setw(4) << previous[i] << "| ";
        diffs[i] = current[i] - previous[i];
    }
    cout << endl;

    // print the current
    cout << "CUR| ";
    for (int i {}; i < months; i++){
        cout << fixed << setprecision(1) << setw(4) << current[i] << "| ";
    }
    cout << endl;

    // print the differences
    cout << "DIF| ";
    for (int i {}; i < months; i++){
        cout << fixed << setprecision(1) << setw(4) << diffs[i] << "| ";
    }
    cout << endl;
    cout << "   |-----------------------------------------------------------------------|" << endl;

}

int main() {
    // Example 1: Slightly wetter current year
    float previous1[12] = { 10.2, 12.5, 15.0, 18.3, 20.1, 25.4, 30.2, 28.9, 22.0, 18.5, 14.3, 11.0 };
    float current1[12]  = { 11.0, 13.1, 16.2, 19.0, 21.5, 26.0, 31.0, 29.5, 23.2, 19.1, 15.0, 12.3 };

    cout << "\n=== Test Case 1 ===\n";
    printRainfall(previous1, current1);

    // Example 2: Drier current year
    float previous2[12] = { 8.0, 9.5, 12.0, 14.0, 16.5, 20.0, 22.5, 21.0, 18.0, 15.0, 10.5, 9.0 };
    float current2[12]  = { 7.2, 8.8, 11.0, 13.1, 15.0, 18.5, 20.0, 19.5, 16.2, 14.0, 9.8, 8.5 };

    cout << "\n=== Test Case 2 ===\n";
    printRainfall(previous2, current2);

    // Example 3: Mixed increases and decreases
    float previous3[12] = { 5.0, 7.0, 9.0, 12.0, 15.0, 18.0, 20.0, 19.0, 16.0, 12.0, 8.0, 6.0 };
    float current3[12]  = { 6.5, 6.0, 10.0, 11.5, 14.0, 19.0, 21.5, 18.0, 17.0, 11.0, 7.5, 7.0 };

    cout << "\n=== Test Case 3 ===\n";
    printRainfall(previous3, current3);

    return 0;
}