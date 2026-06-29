#include <iostream>
using namespace std;

int outOfOrder(const double a[], int size){
    for (int i{}; i < size-1; i++){
        if (a[i] > a[i+1]){
            return i+1;
        }
    }



    return -1;
}

int main()
{
    double a[10] {1.2, 2.1, 3.3, 2.5, 4.5, 7.9, 5.4, 8.7, 9.9, 1.0};
    double b[5] {1,2,3,4, 5.5};
    cout << "Array A is out of order for the first time at index: "<< outOfOrder(a, 10) << endl; 
    cout << "Array B is out of order for the first time at index: "<< outOfOrder(b, 5) << endl; 

    return 0;
}