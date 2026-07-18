#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input {}, output{};
    string current_word{};
    string vowels = "aeiou";

    getline(cin , input);

    for (auto ch : input){
        if (isalpha(ch)){
            current_word += ch;
        } else if (current_word.size() > 0) {
            
            char target = current_word[0]; 
            // starts with a vowel
            if (vowels.find(current_word[0]) != string::npos){
                output += current_word + "way ";
            } else {// start with a consonant
                output += current_word.substr(1) + target + "ay ";
            }
            current_word = "";
        }
    }

    if (current_word.size() > 0 )
    {
        char target = current_word[0]; 
        // starts with a vowel
        if (vowels.find(current_word[0]) != string::npos){
            output += current_word + "way ";
        } else {// start with a consonant
            output += current_word.substr(1) + target + "ay ";
        }
    }
    cout << output << endl;


    return 0;
}