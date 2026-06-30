#include <iostream>
using namespace std;

void fillArray(int a[][5]){
    
    for (int i{}; i < 20; i++){
        cin >> a[i/5][i%5];
    }
}

int main()
{
    int a[4][5] {};
    fillArray(a);
    for (int i {}; i < 20; i++){
        if (i%5==0) cout << endl;
        cout << a[i/5][i%5] << " ";
    }
    return 0;
}