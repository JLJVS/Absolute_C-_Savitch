#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // char stringVar[] = "Hello"; // this creates an array of size 6
    char stringVar[20] = "Hello"; 
    strcat(stringVar, " and Good-bye.");
    cout << stringVar << endl;



    return 0;
}