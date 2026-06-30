#include <iostream>
using namespace std;

void readLetters(){
    char letters[10] {}, letter {};
    cout << "Please enter upto 10 letters: " << endl;
    for (int i {}; i < 10; i++){
        cin >> letter;
        if (letter=='.') break;
        letters[i] = letter;
    }
    for (int i {9}; i >= 0; i--){
        cout << letters[i];
    }
    cout << endl;
}

int main()
{
    readLetters();

    return 0;
}