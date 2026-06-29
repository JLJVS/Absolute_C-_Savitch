#include <iostream>
using namespace std;

void tripler(int& n){
    n = 3*n;
}

int main()
{
    int b[5] {1, 2, 3, 4, 5};
    // note we're starting at index 1 instead of zero and ending at 6 instead of 5 i.e. Out-Of-Bounds
    for (int i=1; i<=5; i++){
        tripler(b[i]);
        cout << "b[" << i <<"]=" << b[i] << endl;
    }


    return 0;
}