#include <iostream>
#include <cctype>
using namespace std;

bool isAlphabet(char c){
    switch (c){
        case ('a'):
        case ('b'):
        case ('c'):
        case ('d'):
        case ('e'):
        case ('f'):
        case ('g'):
        case ('h'):
        case ('i'):
        case ('j'):
        case ('k'):
        case ('l'):
        case ('m'):
        case ('n'):
        case ('o'):
        case ('q'):
        case ('p'):
        case ('r'):
        case ('s'):
        case ('t'):
        case ('u'):
        case ('v'):
        case ('w'):
        case ('x'):
        case ('y'):
        case ('z'):
            return true;
        default:
            return false ;
    }
}

int main(void)
{
    cout << "a: " << isAlphabet('a') << endl;
    cout << "z: " << isAlphabet('z') << endl;
    cout << "0: " << isAlphabet('0') << endl;
    cout << "!: " << isAlphabet('!') << endl;

    return 0;
}