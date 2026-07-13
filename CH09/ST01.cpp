#include <iostream>
using namespace std;

int main()
{
    char stringVar1[10] = "Hello";             // automatically inserts \0 after o
    char stringVar2[10] = {'H', 'e', 'l', 'l', 'o', '\0'}; // equivalent to stringVar1
    char stringVar3[10] = {'H', 'e', 'l', 'l', 'o'}; // this one missees the \0 at the end 
    char stringVar4[6] = "Hello";               // array is Hello\0
    char stringVar5[] = "Hello";                // array is Hello\0

    cout << stringVar1 << endl;
    cout << stringVar2 << endl;
    cout << stringVar3 << endl;
    cout << stringVar4 << endl;
    cout << stringVar5 << endl;



    return 0;
}