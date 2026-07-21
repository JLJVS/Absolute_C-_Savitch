#include <iostream> 
using namespace std;

int main()
{
    int *arrayptr;
    arrayptr = new int[10];

    for (int index{}; index < 10; index++){
        arrayptr[index] = 500 + 2*index;
    }

    for (int index{}; index < 10; index++){
        cout << arrayptr[index] << " "; 
    }
    cout << endl;


    return 0;
}