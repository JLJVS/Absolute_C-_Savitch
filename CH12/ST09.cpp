#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "*" << setw(6) << 1234;
    cout.setf(ios::left);
    cout << "*" << setw(6) << 1234;
    cout.setf(ios::right);
    cout << "*" << setw(6) << 1234 << "*" << endl;

    return 0;
}