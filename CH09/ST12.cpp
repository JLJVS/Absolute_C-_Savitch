#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char aString[20] = "How are you?";
    strcat(aString, "Good, I hope.");// needs a newline or a space before it starts
    cout << aString << endl;

    return 0;
}