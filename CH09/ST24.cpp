#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2("Hello");
    cout << "Enter a line of input:\n";
    cin >> s1;
    if (s1 == s2){
        cout << "Equal\n";
    } else {
        cout << "Not Equal\n";
    }

    return 0;
}