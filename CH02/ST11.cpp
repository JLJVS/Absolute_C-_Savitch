#include <iostream>
using namespace std;


int main(void)
{
    int a =290, b=420, c=1000;
    cout << "Enter three integers\n";
    if ( a>=b){
        cout << "Maximum is a " << a;
    } else {
        cout << " Maximum is c " << c;
    }
    if ( b>= a){
        if (b>=c){
            cout << " Maximum is b " << b;
        } else {
            cout << " Maximum is c " << c;
        }
    }



    return 0;
}