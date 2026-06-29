#include <iostream>
using namespace std;

int main()
{
    double a[10];
    for (double x {}; x < 10; x++){
        a[ (int) x] = 2*x;
    }
    for (int index {}; index < 10; index++){
        // when index is 9 index 10 is out of the array
        if (a[index] > a[index+1]){
            cout << "Array elements " << index << " and " << index +1 << " are out of order." ;
        }
    }



    return 0;
}