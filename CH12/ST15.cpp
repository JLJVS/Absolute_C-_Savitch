#include <iostream>
#include <fstream>
using namespace std;

void copyLine(istream& sourceFile)
{
    char next;
    do
    {
        sourceFile.get(next);
        cout << next;
    } while (     
        next != '\n'
    );
    
}