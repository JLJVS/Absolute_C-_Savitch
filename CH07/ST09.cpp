#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector<int> Evens(10);
    // int index; 
    unsigned int index ; // both work
    for (index = 0; index < Evens.size(); index++){
        Evens[index] = index*2;
    }
    vector<int> Evenscopy;
    Evenscopy = Evens;
    Evens[5] = 420;

    for (index = 0; index < Evenscopy.size(); index++){
        cout << Evenscopy[index] << " ";
    }
    cout << endl;
    return 0;
}