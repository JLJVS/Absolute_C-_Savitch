#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char song[10] = "I did it";
    char franksSong[20];
    strcpy(franksSong, song);
    strcat(franksSong, "My way!");
    cout << franksSong <<endl;
    return 0;
}