#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::cout, std::endl, std::ifstream, std::string, std::setw;


int main()
{   
    string fileName{"PP14data.txt"};
    ifstream inputFile(fileName);
    int lineNum {1};
    bool lineStarted {false}, lineNumPrinted {false};
    char next;

    if (!inputFile) {
        std::cerr << "Error: could not open " << fileName << ".txt\n";
        return 1;
    }

    while (inputFile.get(next))
    {   
        if (!lineNumPrinted){
            cout << setw(3) << lineNum << ": ";
            lineNumPrinted = true;
            lineNum++;
        }
        if (!lineStarted && (next == ' ')){
            continue;
        } else {
            lineStarted = true;
        }
        cout << next;
        if (next == '\n'){
            lineStarted = false;
            lineNumPrinted = false;
        }
    }

    return 0;
}