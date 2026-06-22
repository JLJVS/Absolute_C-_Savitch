#include <iostream>
#include <cmath>
using namespace std;

double babylonian_sqrt(double n){
    double epsilon {n/100.0}, estimate{n/2}, current{n}, r{};
    // cout << "n: " << n << ", estimate: " << estimate << ", epsilon: " << epsilon << endl;
    while (abs(current-estimate) > epsilon){
    //    cout << current << " " << estimate << "\t";
        current = estimate;
        r = n/estimate;
        estimate = (estimate + r)/2;
    }
    //cout << endl;
    //cout << "The square root of " << n << " is " << estimate << endl;
    return estimate;

}

int main(void)
{
    double nums[10] {1,4,9, 30, 95, 1337, 1595, 52345, 2500, 0.5};
    

    for (int i {0}; i < 10; i++){
        cout << "n = " << nums[i] << endl;
        cout << "Math sqrt: \t\t" << sqrt(nums[i]) << endl;
        cout << "Babylonian sqrt:\t" << babylonian_sqrt(nums[i]) << endl <<endl;
        
    }
    return 0;
}