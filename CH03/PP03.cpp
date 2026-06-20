#include <iostream>
using namespace std;

/*
    Write an inflation calculator based on two prices last year and this year. Keeps going as long as the user wants
*/

void inflation_calc(){
    
    float last_year {}, new_year{};
    while (true){
        last_year = 0.0 , new_year = 0.0;
        cout << "Please enter the price last year and the price this year seperated by a space: " ;
        cin >>  last_year >>  new_year;
        if ((new_year == 0)&(last_year==0)) {
            cout << "No prices entered, quitting from the inflation calculator" << endl;
            return;
        }
        cout << "Inflation is: " << (new_year/last_year-1)*100 << "%" << endl;
        cout << "Price in two years will be: " << new_year * (new_year/last_year) * (new_year/last_year) << endl;
    }
}

int main()
{   
    inflation_calc();
    return 0;
}