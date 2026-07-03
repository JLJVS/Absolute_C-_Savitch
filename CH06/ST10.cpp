#include <iostream>
using namespace std;

class Price
{
    public:
        double UnitPrice;
        char Currency;
        void set(double newPrice, char newCurrency);
};
    
void Price::set(double newPrice, char newCurrency){
    UnitPrice = newPrice;
    Currency = newCurrency;
}


int main()
{
    // Test case 1
    Price p1;
    p1.set(19.99, '€');
    cout << "Test 1:\n";
    cout << "UnitPrice: " << p1.UnitPrice << ", Currency: " << p1.Currency << "\n\n";

    // Test case 2
    Price p2;
    p2.set(5.49, '$');
    cout << "Test 2:\n";
    cout << "UnitPrice: " << p2.UnitPrice << ", Currency: " << p2.Currency << "\n\n";

    // Test case 3
    Price p3;
    p3.set(120.00, '£');
    cout << "Test 3:\n";
    cout << "UnitPrice: " << p3.UnitPrice << ", Currency: " << p3.Currency << "\n\n";

    return 0;
}
