#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(int year){
    if (year%400==0){
        return true;
    } else if (year%100==0){
        return false;
    } else if (year%4==0){
        return true;
    }
    return false;
}

int getCenturyValue(int year){
    year /= 100;
    year %= 4;
    return (3-year)*2;
}   

int getYearValue(int year){
    year%=100;
    return year/4 + year;
}

int getMonthValue(int month, int year){
    int val {};
    switch (month){
        case (1):
            val = 0;
            if (isLeapYear(year)){
                val = 6;
            }
            break;
        case (2):
            val = 3;
            if (isLeapYear(year)){
                val = 2;
            }
            break;
        case (3):
        case (11):
            val = 3;
            break;
        case (4):
        case (7):
            val = 6;
            break;
        case (5):
            val = 1;
            break;
        case (6):
            val = 4;
            break;
        case (8):
            val = 2;
            break;
        case (9):
        case (12):
            val = 5;
            break;
        case (10):
            val = 0;
            break;
        default:
            break;       
    }
    return val;
}

void getDayOfWeek(int day, int month, int year){
    int DayOfWeek {day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)};
    DayOfWeek %= 7;
    cout << day << "/" << month << "/" << year << "(dd/mm/yyyy) is the following day of the week: ";
    switch (DayOfWeek){
        case (0):
            cout << "Sunday." << endl;
            break;
        case (1):
            cout << "Monday." << endl;
            break;
        case (2):
            cout << "Tuesday." << endl;
            break;
        case (3):
            cout << "Wednesday." << endl;
            break;
        case (4):
            cout << "Thursday." << endl;
            break;
        case (5):
            cout << "Friday." << endl;
            break;
        case (6):
            cout << "Saturday." << endl;
            break;
        default: 
            cout << "Sunday." << endl;
            break;
    }
}

int main() {
    cout << "Testing getDayOfWeek with 3 example dates:\n\n";

    // Example 1: 1 January 2000
    cout << "1 January 2000 was a Saturday." << endl;
    getDayOfWeek(1, 1, 2000);

    // Example 2: 29 February 2024 (leap year)
    cout << "29 February 2024 was a Thursday." << endl;
    getDayOfWeek(29, 2, 2024);

    // Example 3: 4 July 1776
    cout << "4 July 1776 was a Thursday" << endl;
    getDayOfWeek(4, 7, 1776);

    return 0;
}