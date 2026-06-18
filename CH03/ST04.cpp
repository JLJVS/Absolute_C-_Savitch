#include <iostream>
using namespace std;

int sum(int a, int b){
    return a+b;
}

int main()
{
    for (int a{}; a<10; a++){
        for (int b{5}; b>0; b--){
            cout << "a: " << a << ", b: " << b << ", a + b = " << sum(a,b) << endl;
        }
    }
    
    return 0;
}