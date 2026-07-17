#include <iostream>
#include <cctype>
using namespace std;

const int SIZE {26};

int main()
{
    int letter_count[SIZE] {};
    char ch {};
    bool inWord = false;
    int wordCount {};

    while (cin.get(ch) && ch != '\n'){
        ch = tolower(ch);
        if (isalpha(ch)){
            int index = ch - 'a';
            letter_count[index]++;
            if (! inWord){
                wordCount++;
                inWord = true;
            }
        } else if (ch == ' ' ||  ch == '.' || ch == ','){
            inWord = false; 
        }
    }

    cout << wordCount << " words" << endl;
    for (int index {}; index < SIZE; index++){
        if (letter_count[index] > 0){
            cout << letter_count[index] << " "  << (char) ('a' + index) << endl; 
        }
    }




    return 0;
}