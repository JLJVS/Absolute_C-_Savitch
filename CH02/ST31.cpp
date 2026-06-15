#include <iostream>
using namespace std;

int main()
{
    int n {1024};
    int log {0};
    for (int i {1}; i < n; i = i*2){
        log++;
    }
    cout << n << " " << log << endl;

    // note 2**10 = 2*2*....*2 (10 times) = 4 * 4 * 4 * 4 * 4 = 16 * 16 * 4 = 256 * 4 = 1024





    return 0;
}