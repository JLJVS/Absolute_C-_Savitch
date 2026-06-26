#include <iostream>
using namespace std;

struct imperialHeight{
    int feet;
    int inches;
};

void getImperialUnits(int &meter, int &cm){
    cout << "Please enter the height to be converted from m cm to feet and inches:";
    cin >> meter;
    cin >> cm;
}

imperialHeight convertMetricToImperial(int meter, int cm){
    int total = meter*100 + cm;
    int feet{}, inches{};
    
    while (total>30.48){
        feet++;
        total -= 30.48;
        
    }
    
    inches += (12*total/(30.48));
    imperialHeight h;
    h.feet = feet;
    h.inches = inches;
    
    return h;
}

void printMetric(imperialHeight h){
    cout << h.feet << " feet and " << h.inches << " inches" << endl;
}

int main()
{
    int m{}, cm{};
    imperialHeight h;

    getImperialUnits(m, cm);
    h = convertMetricToImperial(m, cm);
    printMetric(h);

    return 0;
}