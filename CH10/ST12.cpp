#include <iostream>
using namespace std;


int main()
{
    int IntArray[10];
    int arraySize = 10;
    int * IntPtr = IntArray;
    int i ;
    for (i = arraySize-1; i >= 0; i--){
        IntPtr[i] = i;
    }
    for (i = 0; i < arraySize; i++){
        cout << IntPtr[i] << " ";
    }
    cout << endl;

    return 0;
}