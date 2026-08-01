#include <iostream>
#include <fstream>
using namespace std;

void copyCAPS(istream& sourceFile)
{
    char next;
    sourceFile.get(next);
    if (isalpha(next)){
        cout << toupper(next);
    }
    else {
        cout << next;
    }
}