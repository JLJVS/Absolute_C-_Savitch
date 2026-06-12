#include <iostream>
using namespace std;

int main(void)
{

    float loanAmount {1000};
    float percentage {0.15};
    int duration {18};
    float interest {loanAmount*percentage};
    float durationInYears {duration/12.f};
    float totalInterest = interest*durationInYears;
    float total {loanAmount/(1-percentage*durationInYears)};
    float monthlyPayment {total/duration};

    cout << "Desired amount: " << loanAmount << endl;
    cout << "Interest rate: " << percentage << endl;
    cout << "Loan duration in months: " << duration << endl;
    cout << "Loan total: " << total << endl;
    cout << "Face amount: " << total*percentage*durationInYears << endl;
    cout << "Monthly due: " << monthlyPayment << endl;

    return 0;
}