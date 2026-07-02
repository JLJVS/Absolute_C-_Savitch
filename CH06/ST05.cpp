#include <iostream>
using namespace std;

struct DatetoRemember
{
    int month;
    int day;
    int year;
};

void printDate(DatetoRemember d){
    cout << d.day << "/" << d.month << "/" << d.year << endl; 
}

int main()
{
    // a
    DatetoRemember DateofBirth = {11, 02} ;
    cout << "a:" << endl;
    printDate(DateofBirth);

    // b
    DatetoRemember DateofMarriage = {32, 56, 11111};
    cout << "b: " << endl;
    printDate(DateofMarriage);

    // c too many initalizers
    // DatetoRemember DateofRetirement = {12, 21, 2014, 15 ,1,2015};
    // cout << "c: " << endl;
    // printDate(DateofRetirement);

    return 0;   
}