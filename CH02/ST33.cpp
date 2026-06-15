#include <iostream>
using namespace std;

/*
This results in an infinite loop, because 0*2 = 0 for each iteration so an infinite loop....
*/

int main(void)
{
    int n {1024};
    int log {0};
    for (int i{0}; i < n; i *= 2){
        log++;
    }
    cout << n << " " << log << endl;

    return 0;
}