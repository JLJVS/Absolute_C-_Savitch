#include <iostream>
#include <cstring>
using namespace std;

int main()
{   
    cout << "Enter a line of input:\n";
    char next;
    do
    {
        cin.get(next);
        cout << next;
    } while ((!isdigit(next)) && (next != '\n'));
    cout << "END OF OUTPUT";



    return 0;
}