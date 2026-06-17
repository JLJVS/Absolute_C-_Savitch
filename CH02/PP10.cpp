#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(void)
{
    ifstream file("hate.txt");;

    if (!file.is_open()){
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        if (word == "hate"){
            word = "love";
        }
        cout << word << " ";
    }




    return 0;
}