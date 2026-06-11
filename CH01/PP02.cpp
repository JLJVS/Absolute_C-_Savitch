#include <iostream>
using namespace std;

int main(void)
{
    const double percentage {0.001};
    float deadly_dose, mouseWeight, dietWeight;
    float perWeight;

    cout << "What is the deadly dose and what is the weight of the mouse and the dieter?" << endl;
    cin >> deadly_dose >> mouseWeight >> dietWeight;
    perWeight = deadly_dose/mouseWeight;
    cout << "The deadly dose per weight is " << perWeight << endl;
    cout << "A deadly dose for the dieter would be " << perWeight*dietWeight << endl;

    return 0;
}