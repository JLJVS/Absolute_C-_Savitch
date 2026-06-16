#include <iostream>
using namespace std;

int main()
{
    int n_coupons{}, dollars_init{}, dollars{}, chocobars{};
    cout << "How many dollars do you have?\n";
    cin >> dollars;
    dollars_init = dollars;
    while (dollars){
        dollars--;
        chocobars++;
        n_coupons++;
        if (n_coupons%7==0){
            chocobars++;
            n_coupons = 1;
        }
    }
    cout << "Your " << dollars_init << " dollars bought " << chocobars << " chocolate bars and have " << n_coupons << " coupons left" << endl; 


    return 0;
}