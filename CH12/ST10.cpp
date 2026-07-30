#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "*" << setw(6) << 1234 << "*" << 1234 << "*" << endl;
    cout.setf(ios::showpos);
    cout << "*" << setw(6) << 1234 << "*" << 1234 << "*" << endl;
    cout.unsetf(ios::showpos);
    cout.setf(ios::left);
    cout << "*" << setw(6) << 1234 << "*" << 1234 << "*" << endl;
    return 0;
}