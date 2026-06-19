#include <iostream>
using namespace std;

bool even(int n){
    return n%2==0;
}

int main()
{
    for (int i {}; i < 10; i++){
        cout << i << ": even(i)=" << even(i) << endl; 
    }


    return 0;
}