#include <iostream>
using namespace std;

/*
this while loop is an infinite loop because it only stops when x is smaller than zero but it's monotonically increasing and starting above zero.
*/

int main(void)
{
    int x {10};
    while (x > 0){
        cout << x << endl;
        x = x + 3;
    }



    return 0;
}