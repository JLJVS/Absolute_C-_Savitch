#include <iostream>
using namespace std;

int main()
{   
    int itemsArray[70] = {1, 2, 3, 4, 5, 6, 7};
    itemsArray[69] = 6969;
    cout << itemsArray << endl;
    cout << itemsArray + 70 << endl;
    cout << &itemsArray[69] << endl;
    cout << itemsArray[69] << endl;
    cout << "Size of itemsArray " << sizeof(itemsArray) << endl;
    cout << "Size of an integer " << sizeof(int) << endl;
    
    return 0;
}