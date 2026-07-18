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
        output = "";
        current_word = "";

        // step 1 get the input
        getline(cin, input);

        // step 1.5 break if the input is empty
        if (input == ""){
            cout << "bye bye" << endl;
            break;
        }
        for (auto ch: input){
            if (isalpha(ch)){
                current_word += ch;
            } else {
                if (current_word.size()>1 && islower(current_word[0])){
                    int index;
                    for (index = 1; index < current_word.size(); index++){
                        if (!isupper(current_word[index])){
                            break;
                        }
                    }              
                    if (current_word.size()== index){
                        output += current_word;
                        output += " ";
                    }
                }
                current_word = "";
            }
        }
        if (current_word.size()>1 && islower(current_word[0])){
            int index;
            for (index = 1; index < current_word.size(); index++){
                if (!isupper(current_word[index])){
                    break;
                }
            }              
            if (current_word.size() == index){
                output += current_word;
            }
        }
    cout << output << endl;
    }

}