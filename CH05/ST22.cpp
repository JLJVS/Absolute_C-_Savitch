#include <iostream>
using namespace std;

void fillArray(int a[][5]){
    
    for (int i{}; i < 20; i++){
        cin >> a[i/5][i%5];
    }
}

void echoArray(int a[][5], int n){
    for (int i{}; i < n; i++){
        for (int j {}; j < 20; j++){
            if (j%5==0) cout << endl;
            cout << a[j/5][j%5] << " ";
        }
    }
}

int main()
{
    int a[4][5] {};
    fillArray(a);
    echoArray(a, 4);
    return 0;
}