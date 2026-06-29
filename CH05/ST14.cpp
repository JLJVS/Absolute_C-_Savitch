#include <iostream>
using namespace std;

void too2(int a[], int howMany){
    for (int index{}; index< howMany; index++){
        a[index] =2;
    }
}

int main()
{
    int myArray[29];
    too2(myArray, 29);
    too2(myArray, 10);
    // too2(myArray, 55); // not allowed since this will write 2 too memory blocks outside the array
    int yourArray[100] {};
    too2(yourArray, 100);
    too2(yourArray, 29);
    


    return 0;
}