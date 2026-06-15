#include <iostream>
using namespace std;


int main()
{
    int a = 290, b = 4200, c = 1000;

    if (a>=b){
        if (a>= c){
            cout << "Maximum is a " << a;
        } else {
        cout << " Maximum is c " << c;
        } 
    } else {
        if (b>= c){
            cout << " Maximum is b " << b;
        } else {
            cout << " Maximum is c " << c;
        }
    }

    return 0;
}
