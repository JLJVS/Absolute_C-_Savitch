#include <iostream>
using namespace std;


void fiveMore(int a[], int size){
    for (int i{}; i < size; i++){
        a[i] += 5;
    }
}

int main()
{   
    const int N=5;
    int array[N] {}, array2[N]{};
    fiveMore(array, N);
    for (int i{}; i < N; i++){
        cout << array[i] << " ";
        array2[i] = i*i;
    }
    cout << endl;
    fiveMore(array, N);
    for (int i{}; i < N; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    fiveMore(array2, N);
    for (int i{}; i < N; i++){
        cout << array2[i] << " ";
    }
    cout << endl;

    return 0;
}