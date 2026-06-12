#include <iostream>
using namespace std;

int main(void)
{
    const float kgToPounds {2.2}, cmFactor {0.0175};
    float METS{}, weightLB{}, weightKG{}, minutes{};

    cout << "Please enter the weight in pounds: ";
    cin >> weightLB;
    weightKG = weightLB/kgToPounds;
    cout << "Please enter the METS: ";
    cin >> METS;
    cout << "Please the exercise time in minutes: ";
    cin >> minutes;

    float cals {minutes*(cmFactor*METS*weightKG)};
    cout << "The exercise burned " << cals << " cals" << endl;


    return 0;
}