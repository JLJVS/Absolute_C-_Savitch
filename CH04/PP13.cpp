#include <iostream>
using namespace std;

double convertToKPH(int min, int sec){
    int total_sec {60*min+sec};
    double kmPerMile {1.609344};
    double new_time {total_sec/kmPerMile};
    return 3600/new_time;
}

double convertToKPH(double mPH){
    return mPH*1.609344;
}


int main() {
    // Test 1: Convert pace (min/sec per mile) to KPH
    int minutes = 7;
    int seconds = 30;
    double kph_from_pace = convertToKPH(minutes, seconds);

    cout << "Testing convertToKPH(int, int)" << endl;
    cout << "Pace: " << minutes << " min " << seconds << " sec per mile" << endl;
    cout << "Speed in KPH: " << kph_from_pace << endl << endl;

    // Test 2: Convert MPH to KPH
    double mph = 10.0;
    double kph_from_mph = convertToKPH(mph);

    cout << "Testing convertToKPH(double)" << endl;
    cout << mph << " MPH = " << kph_from_mph << " KPH" << endl;

    return 0;
}