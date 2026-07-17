#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main()
{
    string first {}, second {}, third {};
    cin >> first >> second;

    if (cin.peek() != '\n'){
        cin >> third;
    } else {
        cout << second << ", " << first << endl;
        return 0;
    }

    cout << third << ", " << first << " " << (char) toupper(second[0]) << "." << endl;
    
    return 0;
}