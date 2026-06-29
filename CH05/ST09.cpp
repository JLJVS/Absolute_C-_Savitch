#include <iostream>
using namespace std;


int main()
{   
    const int N {15000};
    int autofill[N] {};
    for (int i{}; i < N; i++ ){
        autofill[i] = i;
    }
    cout << "Entry 0: " << autofill[0] << endl;
    cout << "Entry 1000: " << autofill[1000] << endl;
    cout << "Entry 3579: " << autofill[3579] << endl;
    cout << "Entry 14999: " << autofill[14999] << endl;

    return 0;
}