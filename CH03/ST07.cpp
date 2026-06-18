#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

char Compare(int, int);

int main()
{
    int Fn = -10999, Sn=5;
    cout << Fn << Compare(-10999,5) << Sn;
    return 0;
}

char Compare(int first, int second){
    return first > second ? '>' : '<';
}