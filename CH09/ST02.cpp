#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char singingString[20] = "DoBeDo";
    cout << singingString << endl;
    strcat(singingString, " to you"); // 20 is long enough to contain the extra characters: DoBeDo\0 = 7? ' to you\0' 8 -> at most 15 probably 14
    cout << singingString << endl;


    return 0;
}
