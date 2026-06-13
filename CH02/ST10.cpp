#include <iostream>
using namespace std;

int main(void)
{
    // a
    if(100){
        cout << "100 is true, as it is a nonzero ";
    } else{
        cout << "100 is false";
    }
    cout << endl;

    // b
    if(-1000){
        cout << "-1000 is true";
    } else {
        cout << "-1000 is false";
    }
    cout << endl;

    // c
    if(0){
        cout << "0 is true";
    } else {
        cout << "0 is false";
    }
    cout << endl;


    return 0;
}