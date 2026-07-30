#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream ins;
    ins.open("list.txt");
    int count = 0, next;
    while (ins >> next)
    {
        count++;
        cout << next << endl;
    }
    ins.close();
    cout << count;


    return 0;
}