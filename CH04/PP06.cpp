#include <iostream>
using namespace std;

struct imperialHeight{
    int feet;
    int inches;
};

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



void getMetricUnits(int &meter, int &cm){
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
    
    cout << "Choose which conversion to perform: \n";
    cout << "1: Convert Imperial to metric h: m cm" << endl;
    cout << "2: Convert Metric to imperial h: feet inches" << endl;

    int choice {};
    cin >> choice;

    if (choice==1){

        int feet{}, inch{};
        float cm{};
        getImperialUnits(feet, inch);
        cm = convertImperialToMetric(feet, inch);
        printMetric(cm);

    } else if (choice == 2){

        int m{}, cm{};
        imperialHeight h;

        getImperialUnits(m, cm);
        h = convertMetricToImperial(m, cm);
        printMetric(h);
    }

    

    return 0;
}