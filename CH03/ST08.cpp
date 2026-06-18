#include <iostream>
using namespace std;

double average(int a, int b, int c){
    return (a+b+c)/3.0;
}

int main()
{
    cout << "a=1, b=2, c=3: average= " <<  average(1, 2, 3) << endl;
    cout << "a=4, b=5, c=7: average= " <<average(4, 5, 7) << endl;
    cout << "a=-1, b=0, c=2: average= " <<average(-1, 0, 2) << endl;

    return 0;
}