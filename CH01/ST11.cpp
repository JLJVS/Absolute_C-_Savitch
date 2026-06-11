#include <iostream>
using namespace std;


int main(void)
{   
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << 3.25657 << endl;
    return 0;
}