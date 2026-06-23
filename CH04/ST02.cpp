#include <iostream>
using namespace std;

double totalInches(int feet, int inches){
    return 12*feet + inches;
}

int main()
{

    int feet{1}, inches{2};
    cout << totalInches(feet, inches) << endl;

    return 0;
}