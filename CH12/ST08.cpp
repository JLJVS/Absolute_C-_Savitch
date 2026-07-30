#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "*";
    cout.width(6);
    cout << 1234 << "*" << 1234 << "*" << endl;
    cout <<"*" << setw(6) << 1234 << "*" << 1234 << "*" << endl;


    return 0;
}