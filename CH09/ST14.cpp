#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char myString[80];
    cout << "Enter a line of input:\n";
    cin.getline(myString, 16);
    cout << myString << "<END OF OUTPUT" << endl;

    return 0;
}