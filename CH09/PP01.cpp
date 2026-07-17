#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE {101};


int main()
{
    char line[SIZE];
    int count = 0;
    char ch;

    while (cin.get(ch) && ch != '.' && count < SIZE - 1) {
        // no leading spaces
        if ((count == 0) && (ch == ' ' || ch == '\n')){
            continue;
        }
        if ((ch == ' ') && (line[count - 1] == ' ' || line[count - 1] == '\n') ){
            continue;
        }
        ch = tolower(ch);
        if (ch == '\n') ch = ' ';
        line[count] = ch;
        count++;
    }
    line[0] = toupper(line[0]);
    line[count++] = '.';
    line[count] = '\0';  // terminate manually
    cout << line << endl;
    return 0;
}