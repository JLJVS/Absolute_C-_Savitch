#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    cout << "a: " << endl;
    // a
    while (i<=10){
        if (i < 5 && i != 2){
            cout << "X";
        }
        i++;
    }
    cout << endl;
    for (int j=1; j<5; j++){
        if (j!=2){
            cout << "X";
        }
    }
    cout << endl << endl;


    // b
    cout << "b: " << endl;
    i = 1;
    while (i <=10){
        cout << "X";
        i = i +3;
    }
    cout << endl;
    for (int j=1; j<=10; j = j+3){
        cout << "X";
    }
    cout << endl << endl;
    
    // c
    cout << "c: " << endl;
    long n = 100;
    do
    {
        cout << "X";
        n = n+100;
    } while ( n<1000);
    cout << endl;
    
    for (long j = 100; j<1000; j = j+100){
        cout << "X";
    }
    cout << endl;


    return 0;
}