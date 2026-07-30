#include <fstream>
#include <iostream>
using namespace std;


void toScreen(ifstream& filestream)
{

    int next;
    int sumnext = 0;
    while (filestream >> next)
    {
        cout << next << " ";
        sumnext += next;
    }
    cout << endl << sumnext << endl;
}