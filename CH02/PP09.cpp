#include <iostream>
using namespace std;

double babylonian_sqrt(double n){
    double epsilon {n/100.0}, estimate{n/2}, current{n}, r{};
    cout << "n: " << n << ", estimate: " << estimate << ", epsilon: " << epsilon << endl;
    while (abs(current-estimate) > epsilon){
        cout << current << " " << estimate << "\t";
        current = estimate;
        r = n/estimate;
        estimate = (estimate + r)/2;
    }
    cout << endl;
    cout << "The square root of " << n << " is " << estimate << endl;
    return estimate;

}

int main(void)
{
    double nums[5] {1,4,9, 30, 95};
    double sqrt{};

    for (int i {0}; i < 5; i++){
        sqrt = babylonian_sqrt(nums[i]);
    }
    return 0;
}