#include <iostream>
using namespace std;


int main()
{
    float total{1000}, interest{0.015}, monthly_payment{50}, amount_paid{};
    int months{0};

    while (total+total*interest - monthly_payment >= 0){
        amount_paid += monthly_payment;
        total = total + total*interest - monthly_payment;
        months++;
    } 
    if (total*(1+interest)>0){
        amount_paid += total*(1+interest);
        months++;
    }

    cout << "Your total loan of $1000 with a monthly interest rate of " << interest*100 << "\% took " << months << " months to pay off with a total due of " << amount_paid << endl; 




    return 0;
}