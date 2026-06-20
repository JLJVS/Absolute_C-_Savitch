#include <iostream>
using namespace std;

float loan_calculator(int age, int years_of_exp, float income){
    float minimum {}, amount{0};
    if (age<25){
        return amount;
    }

    if (years_of_exp > 5){
        minimum = 15000;
    }
    return 10*income> minimum ? 10*income : minimum;
}

int main()
{
    int age{20}, age_older{30}, inexp{3}, exp{10};
    float income{50000};

    cout << "Age=" << age << ", years of experience=" << inexp<< ", income=" << income <<endl;
    cout << "You qualify for a loan of: " << loan_calculator(age, inexp, income) <<endl; 

    cout << "Age=" << age_older << ", years of experience=" << inexp<< ", income=" << income <<endl;
    cout << "You qualify for a loan of: " << loan_calculator(age_older, inexp, income)<<endl; 

    cout << "Age=" << age_older << ", years of experience=" << exp<< ", income=" << income <<endl;
    cout << "You qualify for a loan of: " << loan_calculator(age_older, exp, income)<<endl; 



    return 0;
}