#include <iostream>
using namespace std;


int main(void)
{
    float baseRate {40}, overRate{60};
    int minHours {125};
    const float provident {0.05}, incomeTax {0.1}, medical {0.025}, canteen {50};

    float hours {}, totalHours {}, total {};
    cout << "Hours worked this week: " << endl;
    cin >> hours;
    totalHours = 4*hours;
    float grossTotal{}, afterTaxesPercentage{1-provident-incomeTax-medical};
    

    if (totalHours > 125){
        grossTotal = (125*baseRate + (totalHours-125)*overRate - 50);
    } else {
        grossTotal = (baseRate*totalHours - 50);
    }
    float netTotal{grossTotal*afterTaxesPercentage};

    cout << "Hours worked weekly " << hours << " and hours worked per month " << totalHours << endl;
    cout << "Gross pay: " << grossTotal + canteen << endl;
    cout << "Employee provident fund: " << grossTotal*provident << endl;
    cout << "Income tax: " << grossTotal*incomeTax << endl;
    cout << "Medical costs: " << grossTotal*medical << endl;
    cout << "Canteen costs: 50" << endl; 
    cout << "Net income: "  << netTotal << endl;

    return 0;
}