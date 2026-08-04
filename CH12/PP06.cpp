#include <iostream>
#include <fstream>
#include <string>
using std::cout, std::ifstream, std::ofstream, std::string, std::endl;
using std::istream, std::ostream;
using std::cerr;


void merge(istream& file1, istream& file2, ostream& output){
    int val1, val2;
    
    // load the first two values
    bool have1 {file1 >> val1}, have2 {file2 >> val2};
    while (have1 && have2)
    {
        if (val1 < val2){
            output << val1 << " ";
            have1 = static_cast<bool>(file1 >> val1);
        } else {
            output << val2 << " ";
            have2 = static_cast<bool>(file2 >> val2);
        }
    }
    while (have1)
    {
        output << val1 << " ";
        have1 = static_cast<bool>(file1 >> val1);
    }
    while (have2)
    {
        output << val2 << " ";
        have2 = static_cast<bool>(file2 >> val2);
    }
}


int main()
{   
    string fileName1 {"even.txt"}, fileName2 {"odd.txt"}, fileNameResult {"PP06output.txt"};
    ifstream file1(fileName1), file2(fileName2);
    ofstream output(fileNameResult);

    if (!file1)  { cerr << "Error: could not open " << fileName1      << "\n"; return 1; }
    if (!file2)  { cerr << "Error: could not open " << fileName2      << "\n"; return 1; }
    if (!output) { cerr << "Error: could not open " << fileNameResult << "\n"; return 1; }

    merge(file1, file2, output);

    return 0;
}