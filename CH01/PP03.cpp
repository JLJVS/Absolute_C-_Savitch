#include <iostream>
using namespace std;

int main(void)
{
    const float increase {0.076};
    float sal{};
    cout << "Please enter your annual salary" << endl;
    cin >> sal;
    cout << "You are due " << sal * increase/2 << " for the last six months" << endl;
    cout << "Your new annual salary is " << sal*(1+increase) << endl ;
    cout << "Your new monthly salary is " << sal*(1+increase)/12 << endl;


    return 0;
}