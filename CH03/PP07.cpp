#include <iostream>
#include <cmath>
using namespace std;

/*
Create a function that calculates the wind chill index

w = 33 - (10 sqrt(v) - v + 10.5)(33 - t)/(23.1)
*/

float calc_wind_chill(float wind_speed, float temperature){
    float w = 33 - (10*sqrt(wind_speed) - wind_speed + 10.5)*(33 - temperature)/23.1;
    return w;
}

int main() {
    // Test case 1
    float w1 = calc_wind_chill(5.0, 10.0);
    cout << "Wind speed: 5 m/s, Temp: 10 C -> Wind chill: " << w1 << endl;

    // Test case 2
    float w2 = calc_wind_chill(10.0, 0.0);
    cout << "Wind speed: 10 m/s, Temp: 0 C -> Wind chill: " << w2 << endl;

    // Test case 3
    float w3 = calc_wind_chill(20.0, -5.0);
    cout << "Wind speed: 20 m/s, Temp: -5 C -> Wind chill: " << w3 << endl;

    // Test case 4
    float w4 = calc_wind_chill(1.0, 15.0);
    cout << "Wind speed: 1 m/s, Temp: 15 C -> Wind chill: " << w4 << endl;

    return 0;
}