#include <iostream>
#include <cmath>
using namespace std;

float calc_avg(float s1, float s2, float s3, float s4){
    return (s1+s2+s3+s4)/4;

}

float calc_std(float s1, float s2, float s3, float s4){
    float avg = calc_avg(s1, s2, s3, s4);
    float std = calc_avg((s1-avg)*(s1-avg), (s2-avg)*(s2-avg), (s3-avg)*(s3-avg), (s4-avg)*(s4-avg));
    return std;
}

int main() {
    float s1, s2, s3, s4;

    cout << "Enter four scores: ";
    cin >> s1 >> s2 >> s3 >> s4;

    float avg = calc_avg(s1, s2, s3, s4);
    float std = calc_std(s1, s2, s3, s4);

    cout << "Average: " << avg << endl;
    cout << "Standard deviation (population): " << sqrt(std) << endl;

    return 0;
}