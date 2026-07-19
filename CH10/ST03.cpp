#include <iostream>
using namespace std;

/*
1000 1000
555 1000
555 333
*/


int main()
{
    int *p1, *p2;
    p1 = new int;
    p2 = p1;
    *p2 = 1000;
    cout << *p1 << " " << *p2 << endl;
    p1++;
    *p1 = 555;
    cout << *p1 << " " << *p2 << endl;
    *p2 = 333;
    cout << *p1 << " " << *p2 << endl;
    return 0;
}