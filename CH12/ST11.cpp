#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ofstream fout;

    fout.open("stuff.txt");
    fout << "*" << setw(6) << 1234 << "*" << 1234<< "*" << endl;
    fout.setf(ios::showpos);
    fout << "*" << setw(6) << 1234 << "*" << 1234<< "*" << endl;
    fout.unsetf(ios::showpos);
    fout.setf(ios::left);
    fout << "*" << setw(6) << 1234 << "*" << 1234<< "*" << endl;
    return 0;
}