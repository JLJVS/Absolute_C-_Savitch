#include <iostream>
using namespace std;

int main(void)
{
    const float registration {0.04}, roadTax {0.02}, insurance {.025}, extendedWarranty {0.015}, serviceTax {0.12};
    float price{};

    cout << "What's the showroom price of the car?" << endl;
    cin >> price;

    float total{price * (1+ registration + roadTax + insurance + extendedWarranty)};
    float afterTaxes{total*(1+serviceTax)};

    cout << "Showroom price: " << price <<endl;
    cout << "Registration fee: " << price*registration << endl;
    cout << "Insurance fee: " << price*insurance << endl;
    cout << "Extended warranty: " << price*extendedWarranty <<endl;
    cout << "After fees: " << total << endl;
    cout << "Service tax: " << total*serviceTax << endl;
    cout << "After taxes: " << afterTaxes << endl;

    return 0;
}