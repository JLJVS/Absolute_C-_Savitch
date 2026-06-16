#include <iostream>
using namespace std;


int main()
{   
    const int N{6};
    bool Passed{true};
    int grades[N] {};
    float total {}, avg{};
    cout << "Please enter your grades, You need a minimum of 40 in each grade to pass: ";
    for (int i{}; i < N; i++){
        cin >> grades[i];
        if (grades[i] < 40){
            Passed = false;
        } else{
            total += grades[i];
        }
    }
    if (Passed){
        avg = total / N;
    if (avg > 90){
        cout << "AA";
    } else if (avg > 80){
        cout << "AB";
    } else if (avg > 70){
        cout << "BB";
    } else if (avg > 60){
        cout << "BC";
    } else if (avg > 50){
        cout << "CC";
    } else if (avg >= 40){
        cout <<  "CD";
    } else if (avg >= 35){
        cout << "DD You didn't get a 40 in one or more grades -> Fail.";
    } else {
        cout << "FF You didn't get a 40 in one or more grades -> Fail.";
    }
    } else {
        cout << "You didn't get a 40 in one or more grades -> Fail.";
    }

    return 0;
}