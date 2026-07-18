#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input{}, output {};
    string current_word {};
    

    while (true){
        // reset all strings
        input = "";
        current_word = "";
        output = "";
        // step 1 read the whole line
        cout << "Enter a sentence to learn to love or you can quit by entering a blank line " << endl;
        getline(cin , input);
        if (input == ""){
            cout << "Byebye" << endl;
            break;
        }

        // step 2 scanning for words 
        for (auto ch: input){
            if (isalpha(ch)){
                current_word += ch;
            } else {
                if (current_word.size() == 4){
                    if (isupper(current_word[0])){
                        current_word = "Love";
                    } else {
                        current_word = "love";
                    }
                }
                if (current_word.size() > 0){
                    output += current_word;
                }
                output += ch;
                    current_word = "";
            }
            
        }
        if (current_word.size() == 4){
            if (isupper(current_word[0])){
                current_word = "Love";
            } else {
                current_word = "love";
            }
        }
        if (current_word.size() > 0){
            output += current_word;
        }
        
        cout << output << endl;
    }
    
    return 0;
}