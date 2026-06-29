#include <iostream>
using namespace std;

int main()
{
    int itemsArray[10];
    // note this index goes to 10 so it's an array with 11 items instead of 10
    for (int index=0; index <= 10; index++){
        itemsArray[index] = 3*index;
        cout << itemsArray[index] << " ";
    }


    return 0;
}