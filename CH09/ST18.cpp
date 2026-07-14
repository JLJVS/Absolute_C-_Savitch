#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char next;
    int count = 0;
    cout << "Enter a line of input:\n";
    cin >> next;
    while (next != '\n'){
        if ((count%2) == 0){
            cout << next;
        }
        count++;
        cin >> next;
    }



    return 0;
}