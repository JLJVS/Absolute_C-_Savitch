#include <iostream>
#include <fstream>
using namespace std;

/*  
    Wrong version: 

    bool moreToRead = true;
    while (moreToRead){
        string text;
        moreToRead = inputStream >> text;
        cout << text << endl;
    }


*/

int main()
{
    bool moreToRead = true;
    string text;
    fstream inputStream;
    inputStream.open("example.txt");

    while (inputStream >> text){
        cout << text << endl;
    }

    inputStream.close();
    return 0;
}