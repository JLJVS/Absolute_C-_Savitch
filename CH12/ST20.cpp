#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main()
{   
    stringstream ssList, ssNum;
    string numbers = "1.1, 1.2, 1.3";

    double total = 0;
    double num;

    ssList.clear();
    ssList.str(numbers);

    string field;
    while(getline(ssList, field, ',')){
        ssNum.clear();
        ssNum.str(field);// we need to clear it first
        ssNum >> num;
        total += num;
    }

    cout << total << endl;

    return 0;
}