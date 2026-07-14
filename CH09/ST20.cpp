#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char line[100];
    cout << "Enter a line of input:\n";
    cin.getline(line, 99);

    char next;
    int index {};

    for (auto c : line){
        if (c == '\0') break;
        if (isupper(c)){
            cout << " ";
        } else {
            cout << c;
        }

    }



    return 0;
}