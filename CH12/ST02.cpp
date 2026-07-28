#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;



int main()
{
    ifstream inFile;
    inFile.open("InputData.txt");
    if (inFile.fail()){
        cout << "Input file opening failed.\n";
        exit(1);
    }

    ofstream outFile;
    outFile.open("OutputData.txt");
    if (outFile.fail()){
        cout << "Output file opening failed.\n";
        exit(1);       

    }

}
