#include <iostream>
using namespace std;

int main(void)
{
    const int candybarCost {10}, gumballCost{3};
    int coupons{};
    cout << "Please enter the number of coupons you won: " << endl;
    cin >> coupons;

    cout << "You can get " << coupons / candybarCost << " candybars and with the remaining coupons you can get " << (coupons%candybarCost)/gumballCost << " gumballs." << endl;


    return 0;
}