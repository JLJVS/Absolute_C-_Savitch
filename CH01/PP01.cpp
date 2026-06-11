#include <iostream>
using namespace std;

/*
A metric ton is 35,273.92 ounces. Write a program that will read the weight of a package of breakfast cereal in ounces and output the weight in metric tons as well as the number of boxes needed to yield one metric ton of cereal.
typical weight of a box is around 17 ounces.
*/

int main(void)
{
    const float ouncesInAMetricTon {35273.92};
    float weightPerBox;
    cout << "What is the weight of the breakfast cereal in ounces?" << endl;
    cin >> weightPerBox;
    cout << "The weight of a breakfast cereal box in metric tons is " << weightPerBox/ouncesInAMetricTon << endl;
    cout << "You need " << ouncesInAMetricTon/weightPerBox << " boxes of breakfast cereal to reach a metric Ton" << endl; 



    return 0;
}