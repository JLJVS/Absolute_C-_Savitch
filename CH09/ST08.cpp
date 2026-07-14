#include <iostream>
using namespace std;

int main()
{
    char ourString[15] = "Hi there!";
    int index {};

    cout << ourString << endl;

    while (ourString[index] != '\0'){
        ourString[index] = 'X';
        index++;
    }
    cout << ourString << endl;
    return 0;
}