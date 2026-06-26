#include <iostream>
using namespace std;

void getImperialUnits(int &feet, int &inch){
    cout << "Please enter the height to be converted to cm in feet and inches:";
    cin >> feet;
    cin >> inch;
}

float convertImperialToMetric(int feet, int inch){
    return (float)( feet*0.3048 + inch*.3048/12);
}

void printMetric(float cm){
    cout << cm << "M" << endl;
}

int main()
{
    int feet{}, inch{};
    float cm;

    getImperialUnits(feet, inch);
    cm = convertImperialToMetric(feet, inch);
    printMetric(cm);

    return 0;
}