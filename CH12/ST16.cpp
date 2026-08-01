#include <iostream>
#include <fstream>
using namespace std;

istream sourceFile;

void sendLine(ostream& targetStream)
{
    char next;
    do
    {
        sourceFile.get(next);
        if (isalpha(next)){
            cout << toupper(next);
        } else {
            cout << next;
        }
    } while (next != '\n');
    



}